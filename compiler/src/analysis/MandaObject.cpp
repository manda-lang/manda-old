// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaObject.h"

manda::MandaObject::MandaObject(const manda::MandaType *type, SourceSpan sourceSpan)
        : sourceSpan(sourceSpan) {
    this->type = type;
    this->constantValueType = kNone;
    this->constantValue.asUnsigned = 0;
}

const manda::MandaType *manda::MandaObject::GetType() const {
    return type;
}
