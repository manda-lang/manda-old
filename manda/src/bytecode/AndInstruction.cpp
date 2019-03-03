// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

uint8_t manda::bytecode::AndInstruction::getOpcode() const
{
    return 0xc;
}

void manda::bytecode::AndInstruction::accept(BytecodeVisitor &visitor)
{
    visitor.visitAndInstruction(*this);
}

