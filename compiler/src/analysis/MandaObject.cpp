// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaObject.h"

manda::MandaObject::MandaObject(const MandaType &type, const SourceSpan &sourceSpan)
        : sourceSpan(sourceSpan),
          type(type) {
    this->constantValueType = kNone;
    this->constantValue.asUnsigned = 0;
}