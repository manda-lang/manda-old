// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <manda/bytecode/bytecode.hpp>
#include <manda/bytecode/DataSection.hpp>


void manda::bytecode::DataSection::accept(manda::bytecode::BytecodeVisitor &visitor)
{
    visitor.visitDataSection(*this);
}

manda::bytecode::SectionType manda::bytecode::DataSection::getType() const
{
    return DATA_SECTION;
}
