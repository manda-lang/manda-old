// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaObjectOrType.h"

manda::MandaObjectOrType::MandaObjectOrType(manda::MandaObject value) {
    this->asObject = value;
    this->asType = nullptr;
}

manda::MandaObjectOrType::MandaObjectOrType(manda::MandaType *value) {
    this->asType = value;
}

const manda::MandaObject manda::MandaObjectOrType::AsObject() const {
    return asObject;
}

const manda::MandaType *manda::MandaObjectOrType::AsType() const {
    return asType;
}

bool manda::MandaObjectOrType::IsType() const {
    return asType != nullptr;
}
