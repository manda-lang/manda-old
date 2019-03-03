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
#include "CallInstruction.hpp"
#include "CodeSection.hpp"
#include "DataSection.hpp"
#include "DivInstruction.hpp"
#include "DivRemainderInstruction.hpp"
#include "JmpInstruction.hpp"
#include "Kernel.hpp"
#include "Label.hpp"
#include "LIInstruction.hpp"
#include "MovInstruction.hpp"
#include "MulInstruction.hpp"
#include "OrInstruction.hpp"
#include "PanicInstruction.hpp"
#include "PopErrorInstruction.hpp"
#include "PushErrorInstruction.hpp"
#include "RetInstruction.hpp"
#include "SignedInstruction.hpp"
#include "SubInstruction.hpp"
#include "SyscallInstruction.hpp"
#include "UnsignedInstruction.hpp"
#include "XorInstruction.hpp"

namespace manda
{
    namespace bytecode
    {
        class BytecodeVisitor
        {
        public:
            virtual void visitAddInstruction(AddInstruction &ctx);

            virtual void visitAndInstruction(AndInstruction &ctx);

            virtual void visitCallInstruction(CallInstruction &ctx);

            virtual void visitCodeSection(CodeSection &ctx);

            virtual void visitDataSection(DataSection &ctx);

            virtual void visitDivInstruction(DivInstruction &ctx);

            virtual void visitDivRemainderInstruction(DivRemainderInstruction &ctx);

            virtual void visitJmpInstruction(JmpInstruction &ctx);

            virtual void visitKernel(Kernel &ctx);

            virtual void visitLabel(Label &ctx);

            virtual void visitLIInstruction(LIInstruction &ctx);

            virtual void visitMovInstruction(MovInstruction &ctx);

            virtual void visitMulInstruction(MulInstruction &ctx);

            virtual void visitOrInstruction(OrInstruction &ctx);

            virtual void visitPanicInstruction(PanicInstruction &ctx);

            virtual void visitPopErrorInstruction(PopErrorInstruction &ctx);

            virtual void visitPushErrorInstruction(PushErrorInstruction &ctx);

            virtual void visitRetInstruction(RetInstruction &ctx);

            virtual void visitSignedInstruction(SignedInstruction &ctx);

            virtual void visitSubInstruction(SubInstruction &ctx);

            virtual void visitSyscallInstruction(SyscallInstruction &ctx);

            virtual void visitUnsignedInstruction(UnsignedInstruction &ctx);

            virtual void visitXorInstruction(XorInstruction &ctx);
        };
    }
}

#endif //MANDA_BYTECODEVISITOR_HPP
