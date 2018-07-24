// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_BLOCK_H
#define MANDA_BLOCK_H

#include <vector>
#include "../runtime/SymbolTable.h"
#include "Instruction.h"

namespace manda
{
    class Object;

    class Block
    {
    public:
        explicit Block(SymbolTable<Object *> *scope);

        ~Block();

        std::vector<Instruction *> &GetInstructions();

        SymbolTable<Object *> *GetScope();

    private:
        std::vector<Instruction *> instructions;
        SymbolTable<Object *> *scope;
    };
}

#endif //MANDA_BLOCK_H
