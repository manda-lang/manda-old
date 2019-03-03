// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_BYTECODEVISITOR_HPP
#define MANDA_BYTECODEVISITOR_HPP

#include "AddInstruction.hpp"
#include "AndInstruction.hpp"
#include "CodeSection.hpp"
#include "DataSection.hpp"
#include "Kernel.hpp"
#include "Label.hpp"
#include "SyscallInstruction.hpp"

namespace manda
{
    namespace bytecode
    {
        class BytecodeVisitor
        {
        public:
            virtual void visitAddInstruction(AddInstruction &ctx);

            virtual void visitAndInstruction(AndInstruction &ctx);

            virtual void visitCodeSection(CodeSection &ctx);

            virtual void visitDataSection(DataSection &ctx);

            virtual void visitKernel(Kernel &ctx);

            virtual void visitLabel(Label &ctx);

            virtual void visitSyscallInstruction(SyscallInstruction &ctx);
        };
    }
}

#endif //MANDA_BYTECODEVISITOR_HPP
