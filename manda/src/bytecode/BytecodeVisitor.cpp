// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/BytecodeVisitor.hpp>

void manda::bytecode::BytecodeVisitor::visitAddInstruction(manda::bytecode::AddInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitAndInstruction(manda::bytecode::AndInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitCallInstruction(manda::bytecode::CallInstruction &ctx)
{
    // Do nothing.
}

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

void manda::bytecode::BytecodeVisitor::visitDivInstruction(manda::bytecode::DivInstruction &ctx)
{

    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitDivRemainderInstruction(manda::bytecode::DivRemainderInstruction &ctx)
{

    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitJmpInstruction(manda::bytecode::JmpInstruction &ctx)
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
    for (auto &instruction : ctx.getInstructions()) {
        instruction.accept(*this);
    }
}

void manda::bytecode::BytecodeVisitor::visitLIInstruction(manda::bytecode::LIInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitMovInstruction(manda::bytecode::MovInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitMulInstruction(manda::bytecode::MulInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitOrInstruction(manda::bytecode::OrInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitPanicInstruction(manda::bytecode::PanicInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitPopErrorInstruction(manda::bytecode::PopErrorInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitPushErrorInstruction(manda::bytecode::PushErrorInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitRetInstruction(manda::bytecode::RetInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitSignedInstruction(manda::bytecode::SignedInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitSubInstruction(manda::bytecode::SubInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitSyscallInstruction(manda::bytecode::SyscallInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitUnsignedInstruction(manda::bytecode::UnsignedInstruction &ctx)
{
    // Do nothing.
}

void manda::bytecode::BytecodeVisitor::visitXorInstruction(manda::bytecode::XorInstruction &ctx)
{
    // Do nothing.
}
