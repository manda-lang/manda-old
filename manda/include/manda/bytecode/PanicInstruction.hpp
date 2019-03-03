// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_PANICINSTRUCTION_HPP
#define MANDA_PANICINSTRUCTION_HPP

#include <cstdint>
#include "Instruction.hpp"

namespace manda
{
    namespace bytecode
    {
        struct PanicInstruction : public Instruction
        {
            uint8_t exc;

            uint8_t getOpcode() const override;

            void accept(BytecodeVisitor &visitor) override;
        };
    }
}

#endif //MANDA_PANICINSTRUCTION_HPP
