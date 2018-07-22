// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "ProgramNode.h"

using namespace manda;

manda::ProgramNode::ProgramNode() = default;

manda::ProgramNode::~ProgramNode() {
    for (auto *statement : statements) {
        delete statement;
    }
}

const std::vector<StatementNode *> &manda::ProgramNode::GetStatements() const {
    return statements;
}

std::vector<StatementNode *> &manda::ProgramNode::GetMutableStatements() {
    return statements;
}
