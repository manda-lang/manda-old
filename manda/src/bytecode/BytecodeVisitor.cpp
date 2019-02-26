// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/BytecodeVisitor.hpp>

void manda::bytecode::BytecodeVisitor::visitDataSection(manda::bytecode::DataSection &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitKernel(manda::bytecode::Kernel &ctx)
{
    for (auto &section : ctx.sections) {
        section.accept(*this);
    }
}
