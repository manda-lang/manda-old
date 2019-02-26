// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/BytecodeVisitor.hpp>
#include <manda/bytecode/Kernel.hpp>


void manda::bytecode::Kernel::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitKernel(*this);
}
