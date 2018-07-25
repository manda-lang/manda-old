// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_INSTRUCTION_H
#define MANDA_INSTRUCTION_H

namespace manda
{
    class Interpreter;

    class Instruction
    {
    public:
        virtual ~Instruction();
        virtual void AcceptInterpreter(Interpreter *interpreter) const = 0;
    };
}

#endif //MANDA_INSTRUCTION_H
