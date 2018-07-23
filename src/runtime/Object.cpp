// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#define MAX_LONG 0xFFFFFFFFFFFFFFFF

#include "Object.h"

manda::Object::Object() {
    asDouble = 0;
}

manda::Object::ObjectType manda::Object::GetType() const {
    // Get the bottom 3 bits
    auto bottom3 = (uint8_t) (asUlong & 0x7);
    return (ObjectType) bottom3;
}

double manda::Object::GetRawDouble() const {
    return asDouble;
}

void manda::Object::SetType(manda::Object::ObjectType type) {
    asUlong |= (uint64_t) type;
}

uint64_t manda::Object::GetData() const {
    return asUlong >> 3;
}

void manda::Object::SetData(uint64_t data) {
    ObjectType currentType = GetType();
    asUlong = data << 3;
    SetType(currentType);
}

float manda::Object::GetFloatData() const {
    return (float) GetData();
}

void manda::Object::SetFloatData(float data) {
    auto asDouble = (double) data;
    SetData((uint64_t) asDouble);
}

manda::Object::Object(uint64_t raw) {
    asUlong = raw;
}

manda::Object::Object(double raw) {
    asDouble = raw;
}

uint64_t manda::Object::GetRawUlong() const {
    return asUlong;
}
