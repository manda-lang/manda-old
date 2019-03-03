// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

uint8_t manda::bytecode::DivInstruction::getOpcode() const
{
    return 0x12;
}

void manda::bytecode::DivInstruction::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitDivInstruction(*this);
}        
        