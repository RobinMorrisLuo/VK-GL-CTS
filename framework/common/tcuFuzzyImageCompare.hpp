#ifndef _TCUFUZZYIMAGECOMPARE_HPP
#define _TCUFUZZYIMAGECOMPARE_HPP
/*-------------------------------------------------------------------------
 * drawElements Quality Program Tester Core
 * ----------------------------------------
 *
 * Copyright 2014 The Android Open Source Project
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
 * \brief Fuzzy image comparison.
 *//*--------------------------------------------------------------------*/

#include "tcuDefs.hpp"

namespace tcu
{

class ConstPixelBufferAccess;
class PixelBufferAccess;

struct FuzzyCompareParams
{
    FuzzyCompareParams(int maxSampleSkip_ = 8, bool returnMaxError_ = false)
        : maxSampleSkip(maxSampleSkip_)
        , returnMaxError(returnMaxError_)
    {
    }

    int maxSampleSkip;
    bool returnMaxError;
};

float fuzzyCompare(const FuzzyCompareParams &params, const ConstPixelBufferAccess &ref,
                   const ConstPixelBufferAccess &cmp, const PixelBufferAccess &errorMask);

} // namespace tcu

#endif // _TCUFUZZYIMAGECOMPARE_HPP
