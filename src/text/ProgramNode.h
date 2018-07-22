// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PROGRAMNODE_H
#define MANDA_PROGRAMNODE_H

#include <vector>
#include "StatementNode.h"

namespace manda
{
    class ProgramNode
    {
    public:
        explicit ProgramNode();
        ~ProgramNode();

        const std::vector<StatementNode *> &GetStatements() const;

        std::vector<StatementNode *> &GetMutableStatements();

    private:
        std::vector<StatementNode *> statements;
    };
}

#endif //MANDA_PROGRAMNODE_H
