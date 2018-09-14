// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "CfgStatement.h"

manda::CfgStatement::CfgStatement(manda::SymbolTable *symbolTable) {
    this->symbolTable = symbolTable;
}

manda::CfgStatement::~CfgStatement() {
    delete symbolTable;
}

const manda::SymbolTable *manda::CfgStatement::GetSymbolTable() const {
    return symbolTable;
}
