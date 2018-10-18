// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaCoreTypes.h"
#include "MandaIntegerType.h"

const manda::MandaCoreTypes *manda::MandaCoreTypes::GetInstance() {
    if (instance == nullptr)
        instance = new MandaCoreTypes;
    return instance;
}

void manda::MandaCoreTypes::InjectIntoSymbolTable(manda::SymbolTable &symbolTable) {
    symbolTable.Assign(boolType.GetSimpleName(), &boolType);
    symbolTable.Assign(int8Type->GetSimpleName(), int8Type);
    symbolTable.Assign(int16Type->GetSimpleName(), int16Type);
    symbolTable.Assign(int32Type->GetSimpleName(), int32Type);
    symbolTable.Assign(int64Type->GetSimpleName(), int64Type);
    symbolTable.Assign(uint8Type->GetSimpleName(), uint8Type);
    symbolTable.Assign(uint16Type->GetSimpleName(), uint16Type);
    symbolTable.Assign(uint32Type->GetSimpleName(), uint32Type);
    symbolTable.Assign(uint64Type->GetSimpleName(), uint64Type);
}

manda::MandaCoreTypes::MandaCoreTypes() {
    this->int8Type = new MandaIntegerType("Int8", 1);
    this->int16Type = new MandaIntegerType("Int16", 2);
    this->int32Type = new MandaIntegerType("Int32", 4);
    this->int64Type = new MandaIntegerType("Int64", 8);
    this->uint8Type = new MandaIntegerType("Uint8", 1);
    this->uint16Type = new MandaIntegerType("Uint16", 2);
    this->uint32Type = new MandaIntegerType("Uint32", 4);
    this->uint64Type = new MandaIntegerType("Uint64", 8);
}

manda::MandaCoreTypes::~MandaCoreTypes() {
    delete int8Type;
    delete int16Type;
    delete int32Type;
    delete int64Type;
    delete uint8Type;
    delete uint16Type;
    delete uint32Type;
    delete uint64Type;
}

const manda::MandaBoolType *manda::MandaCoreTypes::GetBoolType() const {
    return &boolType;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetInt8Type() const {
    return int8Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetInt16Type() const {
    return int16Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetInt32Type() const {
    return int32Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetInt64Type() const {
    return int64Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetUint8Type() const {
    return uint8Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetUint16Type() const {
    return uint16Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetUint32Type() const {
    return uint32Type;
}

const manda::MandaIntegerType *manda::MandaCoreTypes::GetUint64Type() const {
    return uint64Type;
}
