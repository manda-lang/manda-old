// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_EXPRESSIONINSTRUCTION_H
#define MANDA_EXPRESSIONINSTRUCTION_H

#include "Instruction.h"
#include "Object.h"

namespace manda
{
    /**
     * Analogous to an expression statement; represents a standalone expression, the
     * result of which is not stored in memory.
     */
    class ObjectInstruction : public Instruction
    {
    public:
        explicit ObjectInstruction(const Object *object);
        ~ObjectInstruction();

        const Object *GetObject() const;

    private:
        const Object *object;
    };
}

#endif //MANDA_EXPRESSIONINSTRUCTION_H
