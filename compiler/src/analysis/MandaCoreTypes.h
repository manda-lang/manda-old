// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDACORETYPES_H
#define PROJECT_MANDACORETYPES_H

#include "MandaBoolType.h"
#include "MandaIntegerType.h"
#include "SymbolTable.h"

namespace manda
{
    struct MandaCoreTypes
    {
        const MandaBoolType boolType;
        const MandaIntegerType int8Type, int16Type, int32Type, int64Type;
        const MandaIntegerType uint8Type, uint16Type, uint32Type, uint64Type;
        void InjectIntoSymbolTable(SymbolTable &symbolTable) const;
        MandaCoreTypes();
    };
}


#endif //PROJECT_MANDACORETYPES_H
