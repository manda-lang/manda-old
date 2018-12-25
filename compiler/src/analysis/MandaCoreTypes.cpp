// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaCoreTypes.h"
#include "MandaIntegerType.h"


manda::MandaCoreTypes::MandaCoreTypes()
        : int8Type(MandaIntegerType("Int8", 1)),
          int16Type(MandaIntegerType("Int16", 2)),
          int32Type(MandaIntegerType("Int32", 4)),
          int64Type(MandaIntegerType("Int64", 8)),
          uint8Type(MandaIntegerType("Uint8", 1)),
          uint16Type(MandaIntegerType("Uint16", 2)),
          uint32Type(MandaIntegerType("Uint32", 4)),
          uint64Type(MandaIntegerType("Uint64", 8)) {

}

void manda::MandaCoreTypes::InjectIntoSymbolTable(manda::SymbolTable &symbolTable) const {
    symbolTable.assign(boolType.simpleName(), boolType);
    symbolTable.assign(int8Type.simpleName(), int8Type);
    symbolTable.assign(int16Type.simpleName(), int16Type);
    symbolTable.assign(int32Type.simpleName(), int32Type);
    symbolTable.assign(int64Type.simpleName(), int64Type);
    symbolTable.assign(uint8Type.simpleName(), uint8Type);
    symbolTable.assign(uint16Type.simpleName(), uint16Type);
    symbolTable.assign(uint32Type.simpleName(), uint32Type);
    symbolTable.assign(uint64Type.simpleName(), uint64Type);
}