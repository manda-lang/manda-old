// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_CALLINSTRUCTION_HPP
#define MANDA_CALLINSTRUCTION_HPP

#include <cstdint>
#include "Instruction.hpp"

namespace manda
{
    namespace bytecode
    {
        struct CallInstruction : public Instruction
        {
            uint64_t offset;

            uint8_t getOpcode() const override;

            void accept(BytecodeVisitor &visitor) override;
        };
    }
}

#endif //MANDA_CALLINSTRUCTION_HPP
