// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_CFGVALUESTATEMENT_H
#define PROJECT_CFGVALUESTATEMENT_H

#include "CfgStatement.h"

namespace manda
{
    class CfgValueStatement : public CfgStatement
    {
    public:
        CfgValueStatement(const MandaObjectOrType *value, SymbolTable *symbolTable);

        const MandaObjectOrType *GetValue() const;

    private:
        const MandaObjectOrType *value;
    };
}

#endif //PROJECT_CFGVALUESTATEMENT_H
