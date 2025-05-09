/*
 * Copyright (c) 2024, Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

////////////////////////////////////////////////////////////////////////////////
// !!! WARNING - AUTO GENERATED FILE. DO NOT EDIT DIRECTLY. !!!
// Generated by KernelBinToSource.exe tool
////////////////////////////////////////////////////////////////////////////////

#if !defined(MEDIA_BIN_DLL)
#include "vp_platform_interface.h"
#include "vp_render_common.h"
#endif
#include "igvpfc_444PL3_output_xe2.h"

#if defined(MEDIA_BIN_SUPPORT) && !defined(MEDIA_BIN_DLL)

unsigned int IGVPFC_444PL3_OUTPUT_GENERATION_XE2_SIZE = 0;
unsigned int *IGVPFC_444PL3_OUTPUT_GENERATION_XE2 = nullptr;
static bool getIGVPFC_444PL3_OUTPUT_XE2 = LoadMediaBin(IGVPFC_444PL3_OUTPUT_GENERATION_XE2_NAME, &IGVPFC_444PL3_OUTPUT_GENERATION_XE2_SIZE, &IGVPFC_444PL3_OUTPUT_GENERATION_XE2);

#endif  // defined(MEDIA_BIN_SUPPORT) && !defined(MEDIA_BIN_DLL)

#if !defined(MEDIA_BIN_DLL)
void AddVpNativeKernelEntryToListFc_444pl3_outputXe2(vp::VpPlatformInterface &vpPlatformInterface)
{
    vp::KRN_ARG IMAGEWRITE_CURBE[] =
    {
        {FC_444PL3_OUTPUT_IMAGEWRITE_INPUTINDEX, 0, 0, 16, vp::ARG_KIND_GENERAL, false, vp::AddressingModeStateful},
        {FC_444PL3_OUTPUT_IMAGEWRITE_OUTPUTINDEX, 16, 0, 16, vp::ARG_KIND_GENERAL, false, vp::AddressingModeStateful},
        {FC_444PL3_OUTPUT_IMAGEWRITE_ENQUEUED_LOCAL_SIZE, 32, 0, 12, vp::ARG_KIND_GENERAL, false, vp::AddressingModeStateful},
        {FC_444PL3_OUTPUT_IMAGEWRITE_GLOBAL_ID_OFFSET, 0, 0, 12, vp::ARG_KIND_INLINE},
        {FC_444PL3_OUTPUT_IMAGEWRITE_LOCAL_SIZE, 12, 0, 12, vp::ARG_KIND_INLINE},
    };

    vp::KRN_EXECUTE_ENV IMAGEWRITE_PARAM =
    {
        0,         //barrier_count
        true,      //disable_mid_thread_preemption
        128,       //grf_count
        false,     //has_global_atomics
        true,      //has_no_stateless_write
        32,        //inline_data_payload_size
        192,       //offset_to_skip_per_thread_data_load
        32,        //simd_size
        true,      //subgroup_independent_forward_progress
        8,         //eu_thread_count
        false,     //has_fence_for_image_access
        false,     //has_sample
        true,      //has_4gb_buffers
        { 0, 0, 0 },         //work_group_walk_order_dimensions
        0,         //private_size
        0         //slm_size
    };

    vp::KRN_BTI IMAGEWRITE_BTI[] =
    {
        {FC_444PL3_OUTPUT_IMAGEWRITE_INPUTPLANE0, 0},
        {FC_444PL3_OUTPUT_IMAGEWRITE_OUTPUTPLANE0, 1},
        {FC_444PL3_OUTPUT_IMAGEWRITE_OUTPUTPLANE1, 2},
        {FC_444PL3_OUTPUT_IMAGEWRITE_OUTPUTPLANE2, 3},
    };

    vpPlatformInterface.InitVpDelayedNativeAdvKernel((uint32_t *)((uint8_t *)IGVPFC_444PL3_OUTPUT_GENERATION_XE2 + 0), 2048, IMAGEWRITE_CURBE, 5, 44, IMAGEWRITE_PARAM, IMAGEWRITE_BTI, 4, "ImageWrite_fc_444PL3_output");

}
#endif

#if !defined(MEDIA_BIN_SUPPORT) || defined(MEDIA_BIN_DLL)
DEFINE_SHARED_ARRAY_SIZE_UINT32(IGVPFC_444PL3_OUTPUT_GENERATION_XE2_SIZE, 2048);
extern const unsigned int IGVPFC_444PL3_OUTPUT_GENERATION_XE2[] =
{
    0x80100061, 0x7f054220, 0x00000000, 0x00000000, 0x80000065, 0x7f258220, 0x02000004, 0xffffffc0, 
    0x80000065, 0x7f058110, 0x01000024, 0x00ff00ff, 0x80001a40, 0x7f258220, 0x02007f24, 0x00000040, 
    0x80001940, 0x7f258220, 0x02007f24, 0x00000000, 0x8000195b, 0x7f048220, 0x01017f24, 0x00c07f04, 
    0x800c0061, 0x04050220, 0x00100104, 0x00000000, 0x80012031, 0x01140000, 0xfa007f8f, 0xf6780003, 
    0x8000c131, 0x030c0800, 0xfa007f8f, 0xf6740003, 0x00000060, 0x00000000, 0x00000000, 0x00000000, 
    0x00000060, 0x00000000, 0x00000000, 0x00000000, 0x00000060, 0x00000000, 0x00000000, 0x00000000, 
    0x3c8ca101, 0x00100000, 0x8000a065, 0x7f058220, 0x02000004, 0xffffffc0, 0x80001940, 0x7f058220, 
    0x02007f04, 0x00000000, 0x80032231, 0x050c0000, 0xfa007f8f, 0xf6740003, 0x2c248161, 0x00100003, 
    0x80000966, 0x80018220, 0x02008000, 0x400004c0, 0x80032241, 0x20010660, 0x01000584, 0x00000314, 
    0xac840053, 0x03430506, 0x80000041, 0x20010660, 0x01000594, 0x00000364, 0xac840053, 0x03ff0509, 
    0x00156052, 0x07040660, 0x010e0604, 0x04040104, 0x00141a52, 0x0a040660, 0x010e0904, 0x04140204, 
    0x00172331, 0x0c440000, 0x20000714, 0x01680a14, 0x80000065, 0x04858660, 0x05000504, 0x00030003, 
    0x80000065, 0x04958660, 0x05000514, 0x00030003, 0x80000065, 0x04a58660, 0x05000524, 0x00030003, 
    0x80000065, 0x04b58660, 0x05000534, 0x00030003, 0x80000065, 0x04c58660, 0x05000544, 0x00030003, 
    0x80000065, 0x04d58660, 0x05000554, 0x00030003, 0x80000065, 0x04e58660, 0x05000564, 0x00030003, 
    0x28200061, 0x00100747, 0x28200061, 0x00100a49, 0x28200061, 0x00100753, 0x28200061, 0x00100a55, 
    0x7c200061, 0x0010075f, 0x7c200061, 0x00100a61, 0x2c100061, 0x0010037f, 0x00148365, 0x14058660, 
    0x06100c04, 0x807fffff, 0x00140065, 0x16058660, 0x06100e04, 0x807fffff, 0x00d41a70, 0x27050660, 
    0x16101404, 0x00100c04, 0x00140065, 0x18058660, 0x06101004, 0x807fffff, 0x00140065, 0x1d058660, 
    0x06100c04, 0x80000000, 0x00941c70, 0x2b050660, 0x16101604, 0x00100e04, 0x80d40070, 0x00018660, 
    0x15000484, 0x00000000, 0x00140065, 0x1a058660, 0x06101204, 0x807fffff, 0x00140065, 0x1f058660, 
    0x06100e04, 0x80000000, 0x00541e70, 0x2f050660, 0x16101804, 0x00101004, 0x00141e6b, 0x25040228, 
    0xd28a2704, 0x0c051d04, 0x80940070, 0x00018660, 0x15000484, 0x00010001, 0x00140065, 0x21058660, 
    0x06101004, 0x80000000, 0x00141e70, 0x33050660, 0x16101a04, 0x00101204, 0x00141e6b, 0x29040228, 
    0xd28a2b04, 0x0e051f04, 0x80540070, 0x00018660, 0x15000484, 0x00020002, 0x04d41e62, 0x20018aa0, 
    0x0a102504, 0x00000000, 0x00140065, 0x23058660, 0x06101204, 0x80000000, 0x00141d6b, 0x2d040228, 
    0xd28a2f04, 0x10052104, 0x80141170, 0x00018660, 0x15000484, 0x00030003, 0x04941d62, 0x20010aa0, 
    0x0a102904, 0x00102000, 0x80d41170, 0x00018660, 0x15000494, 0x00000000, 0x00141c6b, 0x31040228, 
    0xd28a3304, 0x12052304, 0x04541c62, 0x20010aa0, 0x0a102d04, 0x00102000, 0x80941170, 0x00018660, 
    0x15000494, 0x00010001, 0x04141a62, 0x35050aa0, 0x0a103104, 0x00102000, 0x80541170, 0x00018660, 
    0x15000494, 0x00020002, 0x04d40062, 0x22018aa0, 0x0a102504, 0x00000000, 0x80141170, 0x00018660, 
    0x15000494, 0x00030003, 0x04940062, 0x22010aa0, 0x0a102904, 0x00102200, 0x80d41170, 0x00018660, 
    0x150004a4, 0x00000000, 0x04540062, 0x22010aa0, 0x0a102d04, 0x00102200, 0x80941170, 0x00018660, 
    0x150004a4, 0x00010001, 0x04140062, 0x37050aa0, 0x0a103104, 0x00102200, 0x80541170, 0x00018660, 
    0x150004a4, 0x00020002, 0x04d40062, 0x20018aa0, 0x0a102504, 0x00000000, 0x80141170, 0x00018660, 
    0x150004a4, 0x00030003, 0x04940062, 0x20010aa0, 0x0a102904, 0x00102000, 0x80d41170, 0x00018660, 
    0x150004b4, 0x00000000, 0x04540062, 0x20010aa0, 0x0a102d04, 0x00102000, 0x80941170, 0x00018660, 
    0x150004b4, 0x00010001, 0x04140062, 0x39050aa0, 0x0a103104, 0x00102000, 0x80541170, 0x00018660, 
    0x150004b4, 0x00020002, 0x04d40062, 0x22018aa0, 0x0a102504, 0x00000000, 0x80141170, 0x00018660, 
    0x150004b4, 0x00030003, 0x04940062, 0x22010aa0, 0x0a102904, 0x00102200, 0x80d41170, 0x00018660, 
    0x150004c4, 0x00000000, 0x04540062, 0x22010aa0, 0x0a102d04, 0x00102200, 0x80941170, 0x00018660, 
    0x150004c4, 0x00010001, 0x04140062, 0x3b050aa0, 0x0a103104, 0x00102200, 0x80541170, 0x00018660, 
    0x150004c4, 0x00020002, 0x04d40062, 0x20018aa0, 0x0a103504, 0x00000000, 0x80141170, 0x00018660, 
    0x150004c4, 0x00030003, 0x04940062, 0x20010aa0, 0x0a103704, 0x00102000, 0x80d41170, 0x00018660, 
    0x150004d4, 0x00000000, 0x04540062, 0x20010aa0, 0x0a103904, 0x00102000, 0x80941170, 0x00018660, 
    0x150004d4, 0x00010001, 0x04140062, 0x3d050aa0, 0x0a103b04, 0x00102000, 0x80541170, 0x00018660, 
    0x150004d4, 0x00020002, 0x04d40062, 0x22018aa0, 0x0a103504, 0x00000000, 0x80141170, 0x00018660, 
    0x150004d4, 0x00030003, 0x04940062, 0x22010aa0, 0x0a103704, 0x00102200, 0x80d41170, 0x00018660, 
    0x150004e4, 0x00000000, 0x04540062, 0x22010aa0, 0x0a103904, 0x00102200, 0x80941170, 0x00018660, 
    0x150004e4, 0x00010001, 0x04140062, 0x22010aa0, 0x0a103b04, 0x00102200, 0x80541170, 0x00018660, 
    0x150004e4, 0x00020002, 0x04d40062, 0x20018aa0, 0x0a103504, 0x00000000, 0x80141170, 0x00018660, 
    0x150004e4, 0x00030003, 0x04940062, 0x20010aa0, 0x0a103704, 0x00102000, 0x04540062, 0x20010aa0, 
    0x0a103904, 0x00102000, 0x04140062, 0x20010aa0, 0x0a103b04, 0x00102000, 0x28200061, 0x00103d3f, 
    0x28200061, 0x00103d41, 0x28200061, 0x00103d43, 0x28200061, 0x00103d45, 0x00140061, 0x4b050aa0, 
    0x00102200, 0x00000000, 0x00140061, 0x4d050aa0, 0x00102200, 0x00000000, 0x00140061, 0x4f050aa0, 
    0x00102200, 0x00000000, 0x00140061, 0x51050aa0, 0x00102200, 0x00000000, 0x0016a431, 0x00000000, 
    0xda0c47a5, 0x043c3f44, 0x00140061, 0x57050aa0, 0x00102000, 0x00000000, 0x00140061, 0x59050aa0, 
    0x00102000, 0x00000000, 0x00140061, 0x5b050aa0, 0x00102000, 0x00000000, 0x00140061, 0x5d050aa0, 
    0x00102000, 0x00000000, 0x0016a531, 0x00000000, 0xda0c53a6, 0x043c4b44, 0x00162631, 0x00000000, 
    0xda0c5fa7, 0x043c5744, 0x80000031, 0x00000004, 0x30207f0c, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};
#endif // !defined(MEDIA_BIN_SUPPORT) || defined(MEDIA_BIN_DLL)