// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#define MAX_LONG 0xFFFFFFFFFFFFFFFF

#include "TaggedPointer.h"

manda::TaggedPointer::TaggedPointer() {
    asDouble = 0;
}

manda::TaggedPointer::TaggedPointerType manda::TaggedPointer::GetType() const {
    // Get the bottom 3 bits
    auto bottom3 = (uint8_t) (asUlong & 0x7);
    return (TaggedPointerType) bottom3;
}

double manda::TaggedPointer::GetRawDouble() const {
    return asDouble;
}

void manda::TaggedPointer::SetType(manda::TaggedPointer::TaggedPointerType type) {
    asUlong |= (uint64_t) type;
}

uint64_t manda::TaggedPointer::GetData() const {
    return asUlong >> 3;
}

void manda::TaggedPointer::SetData(uint64_t data) {
    TaggedPointerType currentType = GetType();
    asUlong = data << 3;
    SetType(currentType);
}

float manda::TaggedPointer::GetFloatData() const {
    return (float) GetData();
}

void manda::TaggedPointer::SetFloatData(float data) {
    auto asDouble = (double) data;
    SetData((uint64_t) asDouble);
}

manda::TaggedPointer::TaggedPointer(uint64_t raw) {
    asUlong = raw;
}

manda::TaggedPointer::TaggedPointer(double raw) {
    asDouble = raw;
}

uint64_t manda::TaggedPointer::GetRawUlong() const {
    return asUlong;
}
