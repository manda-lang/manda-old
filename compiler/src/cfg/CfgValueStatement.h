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
        CfgValueStatement(const MandaObjectOrType *value, SymbolTable *symbolTable, bool isReturn);

        const MandaObjectOrType *GetValue() const;

        bool IsReturn() const;

    private:
        const MandaObjectOrType *value;
        bool isReturn;
    };
}

#endif //PROJECT_CFGVALUESTATEMENT_H
