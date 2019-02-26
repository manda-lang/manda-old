// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_BYTECODEVISITOR_HPP
#define MANDA_BYTECODEVISITOR_HPP

#include "CodeSection.hpp"
#include "DataSection.hpp"
#include "Kernel.hpp"
#include "Label.hpp"

namespace manda
{
    namespace bytecode
    {
        class BytecodeVisitor
        {
        public:
            virtual void visitCodeSection(CodeSection &ctx);

            virtual void visitDataSection(DataSection &ctx);

            virtual void visitKernel(Kernel &ctx);

            virtual void visitLabel(Label &ctx);
        };
    }
}

#endif //MANDA_BYTECODEVISITOR_HPP
