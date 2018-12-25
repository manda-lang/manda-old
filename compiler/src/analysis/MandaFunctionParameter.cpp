// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaFunctionParameter.h"

manda::MandaFunctionParameter::MandaFunctionParameter
        (std::string name,
         const manda::MandaType *type,
         bool isProperty,
         manda::SourceSpan sourceSpan)
        : name(std::move(name)),
          sourceSpan(std::move(sourceSpan)) {
    this->type = type;
    this->isProperty = isProperty;
}

const std::string &manda::MandaFunctionParameter::GetName() const {
    return name;
}

bool manda::MandaFunctionParameter::IsProperty() const {
    return isProperty;
}

const manda::MandaType *manda::MandaFunctionParameter::GetType() const {
    return type;
}

const manda::SourceSpan &manda::MandaFunctionParameter::GetSourceSpan() const {
    return sourceSpan;
}
