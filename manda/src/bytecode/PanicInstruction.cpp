// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

uint8_t manda::bytecode::PanicInstruction::getOpcode() const
{
    return 0x19;
}

void manda::bytecode::PanicInstruction::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitPanicInstruction(*this);
}        
        