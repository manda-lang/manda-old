// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#ifndef MANDA_BYTECODEVISITOR_HPP
#define MANDA_BYTECODEVISITOR_HPP

#include "Kernel.hpp"

namespace manda
{
    namespace bytecode
    {
        class BytecodeVisitor
        {
        public:
            virtual void visitKernel(Kernel &ctx);
        };
    }
}

#endif //MANDA_BYTECODEVISITOR_HPP
