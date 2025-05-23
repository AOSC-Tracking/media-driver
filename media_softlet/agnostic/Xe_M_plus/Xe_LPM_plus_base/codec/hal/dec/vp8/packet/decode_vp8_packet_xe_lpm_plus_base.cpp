/*
* Copyright (c) 2020-2022, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     decode_vp8_packet_xe_lpm_plus_base.cpp
//! \brief    Defines the interface for vp8 decode packet of Xe_LPM_plus+
//!
#include "decode_vp8_packet_xe_lpm_plus_base.h"
#include "decode_utils.h"
#include "decode_vp8_pipeline.h"
#include "decode_vp8_basic_feature.h"
#include "decode_vp8_reference_frames.h"
#include "decode_status_report_defs.h"
#include "mos_solo_generic.h"
#include "decode_status_report_defs.h"
#include "decode_resource_auto_lock.h"
#include "hal_oca_interface_next.h"
#include "mhw_vdbox_xe_lpm_plus_base.h"

using namespace mhw::vdbox::xe_lpm_plus_base;

namespace decode
{
    MOS_STATUS Vp8DecodePktXe_Lpm_Plus_Base::Submit(
        MOS_COMMAND_BUFFER* cmdBuffer,
        uint8_t packetPhase)
    {
        DECODE_FUNC_CALL();

        PERF_UTILITY_AUTO(__FUNCTION__, PERF_DECODE, PERF_LEVEL_HAL);

        DECODE_CHK_NULL(cmdBuffer);
        DECODE_CHK_NULL(m_hwInterface);

        DECODE_CHK_STATUS(Mos_Solo_PreProcessDecode(m_osInterface, &m_vp8BasicFeature->m_destSurface));

        DECODE_CHK_STATUS(m_miItf->SetWatchdogTimerThreshold(m_vp8BasicFeature->m_width, m_vp8BasicFeature->m_height, false));

        if (IsPrologRequired())
        {
            DECODE_CHK_STATUS(AddForceWakeup(*cmdBuffer));
            DECODE_CHK_STATUS(SendPrologWithFrameTracking(*cmdBuffer, true));
        }

        DECODE_CHK_NULL(m_hwInterface->GetVdencInterfaceNext());
        auto mmioRegisters = m_hwInterface->GetVdencInterfaceNext()->GetMmioRegisters(MHW_VDBOX_NODE_1);
        HalOcaInterfaceNext::On1stLevelBBStart(*cmdBuffer, (MOS_CONTEXT_HANDLE)m_osInterface->pOsContext, m_osInterface->CurrentGpuContextHandle, m_miItf, *mmioRegisters);
        HalOcaInterfaceNext::OnDispatch(*cmdBuffer, *m_osInterface, m_miItf, *m_miItf->GetMmioRegisters());

        DECODE_CHK_STATUS(PackPictureLevelCmds(*cmdBuffer));
        DECODE_CHK_STATUS(PackSliceLevelCmds(*cmdBuffer));

        DECODE_CHK_STATUS(m_miItf->ADDCMD_MI_BATCH_BUFFER_END(cmdBuffer, nullptr));

        HalOcaInterfaceNext::On1stLevelBBEnd(*cmdBuffer, *m_osInterface);

        DECODE_CHK_STATUS(m_allocator->SyncOnResource(&m_vp8BasicFeature->m_resDataBuffer.OsResource, false));

        DECODE_CHK_STATUS(Mos_Solo_PostProcessDecode(m_osInterface, &m_vp8BasicFeature->m_destSurface));

        return MOS_STATUS_SUCCESS;
    }

    MOS_STATUS Vp8DecodePktXe_Lpm_Plus_Base::PackPictureLevelCmds(MOS_COMMAND_BUFFER &cmdBuffer)
    {
        DECODE_FUNC_CALL();
        PERF_UTILITY_AUTO(__FUNCTION__, PERF_DECODE, PERF_LEVEL_HAL);

        DECODE_CHK_STATUS(StartStatusReport(statusReportMfx, &cmdBuffer));
        DECODE_CHK_STATUS(m_picturePkt->Execute(cmdBuffer));

        return MOS_STATUS_SUCCESS;
    }

    MOS_STATUS Vp8DecodePktXe_Lpm_Plus_Base::PackSliceLevelCmds(MOS_COMMAND_BUFFER &cmdBuffer)
    {
        DECODE_FUNC_CALL();
        PERF_UTILITY_AUTO(__FUNCTION__, PERF_DECODE, PERF_LEVEL_HAL);

        DECODE_CHK_STATUS(m_slicePkt->Execute(cmdBuffer));

        DECODE_CHK_STATUS(MiFlush(cmdBuffer));
        DECODE_CHK_STATUS(EndStatusReport(statusReportMfx, &cmdBuffer));
        DECODE_CHK_STATUS(UpdateStatusReportNext(statusReportGlobalCount, &cmdBuffer));
        DECODE_CHK_STATUS(MiFlush(cmdBuffer));

        return MOS_STATUS_SUCCESS;
    }

}

