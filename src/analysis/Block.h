// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_BLOCK_H
#define MANDA_BLOCK_H

#include <vector>
#include "Instruction.h"

namespace manda
{
    class Block
    {
    public:
        explicit Block();

        ~Block();

        std::vector<Instruction *> &GetInstructions() const;

    private:
        std::vector<Instruction *> instructions;
    };
}

#endif //MANDA_BLOCK_H
