// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "CfgValueStatement.h"

manda::CfgValueStatement::CfgValueStatement(const manda::MandaObjectOrType *value, manda::SymbolTable *symbolTable)
        : CfgStatement(symbolTable) {
    this->value = value;
}


const manda::MandaObjectOrType *manda::CfgValueStatement::GetValue() const {
    return value;
}
