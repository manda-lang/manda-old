// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

manda::bytecode::Label::Label()
{
    mHasName = false;
}

bool manda::bytecode::Label::hasName() const
{
    return mHasName;
}

const std::string &manda::bytecode::Label::getName() const
{
    return name;
}

void manda::bytecode::Label::setName(const std::string &name)
{
    this->name = name;
    mHasName = true;
}

std::vector<manda::bytecode::Instruction> &manda::bytecode::Label::getInstructions()
{
    return instructions;
}

const std::vector<manda::bytecode::Instruction> &manda::bytecode::Label::getInstructions() const
{
    return instructions;
}

void manda::bytecode::Label::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitLabel(*this);
}

