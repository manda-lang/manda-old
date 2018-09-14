// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_CFGBASICBLOCK_H
#define PROJECT_CFGBASICBLOCK_H

#include <vector>

namespace manda
{
    class CfgNode
    {
    public:
        ~CfgNode();

        const std::vector<CfgNode *> &GetChildren() const;

        void AddChild(CfgNode *child);

    protected:
        std::vector<CfgNode *> children;
    };
}


#endif //PROJECT_CFGBASICBLOCK_H
