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
    class MandaCoreTypes
    {
    public:
        static const MandaCoreTypes *GetInstance();

        void InjectIntoSymbolTable(SymbolTable &symbolTable);

        const MandaBoolType *GetBoolType() const;

        const MandaIntegerType *GetInt8Type() const;

        const MandaIntegerType *GetInt16Type() const;

        const MandaIntegerType *GetInt32Type() const;

        const MandaIntegerType *GetInt64Type() const;

        const MandaIntegerType *GetUint8Type() const;

        const MandaIntegerType *GetUint16Type() const;

        const MandaIntegerType *GetUint32Type() const;

        const MandaIntegerType *GetUint64Type() const;

    private:
        static MandaCoreTypes *instance = nullptr;

        MandaCoreTypes();

        ~MandaCoreTypes();

        MandaBoolType boolType;
        MandaIntegerType *int8Type, *int16Type, *int32Type, *int64Type;
        MandaIntegerType *uint8Type, *uint16Type, *uint32Type, *uint64Type;
    };
}


#endif //PROJECT_MANDACORETYPES_H
