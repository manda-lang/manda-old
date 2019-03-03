// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_ORINSTRUCTION_HPP
#define MANDA_ORINSTRUCTION_HPP

#include <cstdint>
#include "Instruction.hpp"

namespace manda
{
    namespace bytecode
    {
        struct OrInstruction : public Instruction
        {
            uint8_t dest, a, b;

            uint8_t getOpcode() const override;

            void accept(BytecodeVisitor &visitor) override;
        };
    }
}

#endif //MANDA_ORINSTRUCTION_HPP