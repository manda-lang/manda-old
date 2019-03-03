// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

uint8_t manda::bytecode::JmpInstruction::getOpcode() const
{
    return 0x17;
}

void manda::bytecode::JmpInstruction::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitJmpInstruction(*this);
}        
        