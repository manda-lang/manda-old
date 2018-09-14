// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_CFGSTATEMENT_H
#define PROJECT_CFGSTATEMENT_H

#include "SymbolTable.h"

namespace manda
{
    class CfgStatement
    {
    public:
        CfgStatement(SymbolTable *symbolTable);

        virtual ~CfgStatement();

        const SymbolTable *GetSymbolTable() const;

    protected:
        SymbolTable *symbolTable;
    };
}

#endif //PROJECT_CFGSTATEMENT_H
