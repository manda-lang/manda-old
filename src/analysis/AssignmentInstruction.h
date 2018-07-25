// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ASSIGNMENTINSTRUCTION_H
#define MANDA_ASSIGNMENTINSTRUCTION_H

#include <string>
#include "Instruction.h"
#include "Object.h"

namespace manda
{
    class AssignmentInstruction : public Instruction
    {
    public:
        explicit AssignmentInstruction(const std::string &name, const Object *object);

        ~AssignmentInstruction();

        const std::string &GetName() const;

        const Object *GetObject() const;

        void AcceptInterpreter(Interpreter *interpreter) const override;

    private:
        std::string name;
        const Object *object;
    };
}

#endif //MANDA_ASSIGNMENTINSTRUCTION_H
