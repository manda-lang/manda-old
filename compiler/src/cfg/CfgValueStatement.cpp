// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "CfgValueStatement.h"

manda::CfgValueStatement::CfgValueStatement(const manda::MandaObjectOrType *value, manda::SymbolTable *symbolTable, bool isReturn)
        : CfgStatement(symbolTable) {
    this->value = value;
    this->isReturn = isReturn;
}


const manda::MandaObjectOrType *manda::CfgValueStatement::GetValue() const {
    return value;
}

bool manda::CfgValueStatement::IsReturn() const {
    return isReturn;
}
