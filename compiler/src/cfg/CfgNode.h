// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_CFGBASICBLOCK_H
#define PROJECT_CFGBASICBLOCK_H

#include <vector>
#include "CfgStatement.h"

namespace manda
{
    class CfgNode
    {
    public:
        ~CfgNode();

        const std::vector<CfgNode *> &GetChildren() const;

        const std::vector<CfgStatement *> GetStatements() const;

        void AddChild(CfgNode *child);

        void AddStatement(CfgStatement *statement);

    private:
        std::vector<CfgNode *> children;
        std::vector<CfgStatement *> statements;
    };
}


#endif //PROJECT_CFGBASICBLOCK_H
