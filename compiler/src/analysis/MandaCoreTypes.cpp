// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaCoreTypes.h"
#include "MandaIntegerType.h"

void manda::MandaCoreTypes::InjectIntoSymbolTable(manda::SymbolTable &symbolTable) {
    symbolTable.Assign("Int8", new MandaIntegerType("Int8", 1));
    symbolTable.Assign("Int16", new MandaIntegerType("Int16", 2));
    symbolTable.Assign("Int32", new MandaIntegerType("Int32", 4));
    symbolTable.Assign("Int64", new MandaIntegerType("Int64", 8));
    symbolTable.Assign("Uint8", new MandaIntegerType("Uint8", 1, true));
    symbolTable.Assign("Uint16", new MandaIntegerType("Uint16", 2, true));
    symbolTable.Assign("Uint32", new MandaIntegerType("Uint32", 4, true));
    symbolTable.Assign("Uint64", new MandaIntegerType("Uint64", 8, true));
}
