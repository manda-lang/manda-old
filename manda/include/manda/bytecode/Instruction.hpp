// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_INSTRUCTION_HPP
#define MANDA_INSTRUCTION_HPP

#include "Node.hpp"

namespace manda
{
    namespace bytecode
    {
        class Instruction : public Node
        {
        public:
            virtual uint8_t getOpcode() const = 0;
        };
    }
}

#endif //MANDA_INSTRUCTION_HPP
