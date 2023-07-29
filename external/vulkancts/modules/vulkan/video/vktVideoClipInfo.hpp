#ifndef _VKTVIDEOCLIPINFO_HPP
#define _VKTVIDEOCLIPINFO_HPP
/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2023 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Reference checksums for video decode validation
 *
 * See the <vulkan_data_dir>/vulkan/video/frame_checksums.py file for
 * instructions on generating the checksums for new tests.
 *--------------------------------------------------------------------*/
#include "deDefs.hpp"
#include "vktVideoTestUtils.hpp"

#include <array>
#include <string>
#include <sstream>

namespace vkt
{
namespace video
{

enum ClipName
{
    CLIP_A = 0,
    CLIP_B,
    CLIP_C,
    CLIP_D,
    CLIP_E,
    CLIP_F,
    CLIP_G,
    CLIP_H,
    CLIP_H264_4K_26_IBP_MAIN,
    CLIP_JELLY_HEVC,
    CLIP_NONE_HEVC,

    CLIP_LAST,
};
struct VideoProfileInfo
{
    VkVideoCodecOperationFlagBitsKHR codecOperation;
    VkVideoChromaSubsamplingFlagBitsKHR subsamplingFlags;
    VkVideoComponentBitDepthFlagBitsKHR lumaBitDepth;
    VkVideoComponentBitDepthFlagBitsKHR chromaBitDepth;
    int profileIDC;

    VideoProfileInfo(VkVideoCodecOperationFlagBitsKHR codecOp,
                     VkVideoChromaSubsamplingFlagBitsKHR subsampleFlags = VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR,
                     VkVideoComponentBitDepthFlagBitsKHR lumaDepth      = VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR,
                     VkVideoComponentBitDepthFlagBitsKHR chromaDepth    = VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR,
                     int profile                                        = 0)
        : codecOperation(codecOp)
        , subsamplingFlags(subsampleFlags)
        , lumaBitDepth(lumaDepth)
        , chromaBitDepth(chromaDepth)
        , profileIDC(profile)
    {
    }
};

struct ClipInfo
{
    ClipName name;
    const char *filename;
    VideoProfileInfo profile;
    uint32_t frameWidth;
    uint32_t frameHeight;
    uint32_t frameRate;
    int totalFrames;
    uint32_t framesInGOP;
    const char **frameChecksums;

    ClipInfo(ClipName cName, const char *fName, VideoProfileInfo vProfile, uint32_t fFrameWidth = 0,
             uint32_t fFameHeight = 0, uint32_t fFrameRate = 0, int tFrames = 0, uint32_t fInGOP = 0,
             const char **fChecksums = nullptr)
        : name(cName)
        , filename(fName)
        , profile(vProfile)
        , frameWidth(fFrameWidth)
        , frameHeight(fFameHeight)
        , frameRate(fFrameRate)
        , totalFrames(tFrames)
        , framesInGOP(fInGOP)
        , frameChecksums(fChecksums)
    {
    }
};

const ClipInfo *clipInfo(ClipName c);
const char *checksumForClipFrame(const ClipInfo *cinfo, int frameNumber);

} // namespace video
} // namespace vkt
#endif // _VKTVIDEOCLIPINFO_HPP
