// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.

#include "Object.h"

manda::Object::Object() {
    raw = 0;
}

manda::Object::Object(uint32_t raw) {
    this->raw = raw;
}

manda::Object::ObjectType manda::Object::GetType() const {
    // Get the bottom 3 bits
    auto bottom3 = (uint8_t) (raw & 0x7);
    return (ObjectType) bottom3;
}

uint32_t manda::Object::GetRaw() const {
    return raw;
}

void manda::Object::SetType(manda::Object::ObjectType type) {
    raw |= (uint32_t) type;
}

uint32_t manda::Object::GetData() const {
    return raw >> 3;
}

void manda::Object::SetData(uint32_t data) {
    ObjectType currentType = GetType();
    raw = data << 3;
    SetType(currentType);
}

float manda::Object::GetFloatData() const {
    return (float) GetData();
}

void manda::Object::SetFloatData(float data) {
    auto asDouble = (double) data;
    SetData((uint32_t) asDouble);
}