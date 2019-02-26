// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_KERNEL_HPP
#define MANDA_KERNEL_HPP

#include <vector>
#include <manda/bytecode/Section.hpp>

namespace manda
{
    namespace bytecode
    {
        struct Kernel : public Node
        {
            std::vector<Section> sections;

            void accept(BytecodeVisitor &visitor) override;
        };
    }
}

#endif //MANDA_KERNEL_HPP
