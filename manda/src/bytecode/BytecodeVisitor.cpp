// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/BytecodeVisitor.hpp>

void manda::bytecode::BytecodeVisitor::visitCodeSection(manda::bytecode::CodeSection &ctx)
{
    for (auto &label : ctx.labels) {
        label.accept(*this);
    }
}

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

void manda::bytecode::BytecodeVisitor::visitLabel(manda::bytecode::Label &ctx)
{
    // Do nothing.
}
