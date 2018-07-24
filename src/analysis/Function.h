// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_FUNCTION_H
#define MANDA_FUNCTION_H

#include <unordered_map>
#include <string>
#include "Block.h"

namespace manda
{
    class Function
    {
    public:
        explicit Function();
        ~Function();

        const std::unordered_map<std::string, Block *>& GetBlocks() const;

        bool HasBlock(std::string &name) const;

        Block *GetBlock(std::string &name) const;

        Block *GetStartBlock() const;

        void SetStartBlock(Block *block);

        void PutBlock(std::string &name, Block *block);

    private:
        std::unordered_map<std::string, Block *> blocks;
    };
}

#endif //MANDA_FUNCTION_H
