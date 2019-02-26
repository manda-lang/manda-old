// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_DATASECTION_HPP
#define MANDA_DATASECTION_HPP

#include <vector>
#include "Section.hpp"

namespace manda
{
    namespace bytecode
    {
        struct DataSection : public Section
        {
            std::vector<char> data;

            void accept(BytecodeVisitor &visitor) override;

            SectionType getType() const override;
        };
    }
}

#endif //MANDA_DATASECTION_HPP
