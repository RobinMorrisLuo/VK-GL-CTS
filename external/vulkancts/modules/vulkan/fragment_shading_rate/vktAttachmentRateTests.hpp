#ifndef _VKTATTACHMENTRATETESTS_HPP
#define _VKTATTACHMENTRATETESTS_HPP
/*-------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2021 The Khronos Group Inc.
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
 * \brief Tests for VK_KHR_fragment_shading_rate.
 *//*--------------------------------------------------------------------*/

#include "tcuDefs.hpp"
#include "tcuTestCase.hpp"
#include "vktFragmentShadingRateGroupParams.hpp"

namespace vkt
{
namespace FragmentShadingRate
{

void createAttachmentRateTests(tcu::TestContext &testCtx, tcu::TestCaseGroup *group, SharedGroupParams groupParams);

} // namespace FragmentShadingRate
} // namespace vkt

#endif // _VKTATTACHMENTRATETESTS_HPP
