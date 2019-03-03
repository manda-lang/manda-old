// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

uint8_t manda::bytecode::XorInstruction::getOpcode() const
{
    return 0xe;
}

void manda::bytecode::XorInstruction::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitXorInstruction(*this);
}        
        