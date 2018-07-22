// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Number.h"

manda::Object::ObjectType manda::Number::get_primitive_type() {
    return Object::NUMBER;
}

manda::Number::Number(double value) {
    this->value = value;
}

void manda::Number::toString(std::ostream &out) {
    out << value;
}

const char *manda::Number::ansiColor() {
    return "\33[0;36m";
}
