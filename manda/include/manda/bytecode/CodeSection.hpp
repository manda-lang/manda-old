// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_CODESECTION_HPP
#define MANDA_CODESECTION_HPP

#include <vector>
#include "Label.hpp"
#include "Section.hpp"

namespace manda
{
    namespace bytecode
    {
        struct CodeSection : public Section
        {
            std::vector<Label> labels;
        };
    }
}

#endif //MANDA_CODESECTION_HPP
