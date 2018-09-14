// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "CfgNode.h"

manda::CfgNode::~CfgNode() {
    for (auto *child: children) {
        delete child;
    }
}

const std::vector<manda::CfgNode *> &manda::CfgNode::GetChildren() const {
    return children;
}

void manda::CfgNode::AddChild(manda::CfgNode *child) {
    children.push_back(child);
}

const std::vector<manda::CfgStatement *> manda::CfgNode::GetStatements() const {
    return statements;
}

void manda::CfgNode::AddStatement(manda::CfgStatement *statement) {
    statements.push_back(statement);
}
