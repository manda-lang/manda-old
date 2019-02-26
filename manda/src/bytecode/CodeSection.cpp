// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>

void manda::bytecode::CodeSection::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitCodeSection(*this);
}

manda::bytecode::SectionType manda::bytecode::CodeSection::getType() const
{
    return CODE_SECTION;
}
