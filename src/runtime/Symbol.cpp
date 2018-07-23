// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Symbol.h"

template<typename T>
manda::Symbol<T>::Symbol(const std::string &name, T *value) {
    this->name += name;
    this->value = value;
}

template<typename T>
const std::string &manda::Symbol<T>::GetName() const {
    return name;
}

template<typename T>
T *manda::Symbol<T>::GetValue() {
    return value;
}
