// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "CompilationUnitNode.h"

using namespace manda;

manda::CompilationUnitNode::CompilationUnitNode() = default;

manda::CompilationUnitNode::~CompilationUnitNode() {
    for (auto *statement : statements) {
        delete statement;
    }

    statements.clear();
}

const std::vector<StatementNode *> &manda::CompilationUnitNode::GetStatements() const {
    return statements;
}

std::vector<StatementNode *> &manda::CompilationUnitNode::GetMutableStatements() {
    return statements;
}
