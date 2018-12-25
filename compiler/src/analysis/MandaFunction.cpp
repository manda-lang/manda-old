// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "MandaFunction.h"

manda::MandaFunction::MandaFunction(const MandaType *returnType, const SourceSpan &sourceSpan)
        : MandaObject(nullptr, sourceSpan) {
    this->returnType = returnType;
}

manda::MandaFunction::~MandaFunction() {
    for (auto * parameter : parameters) {
        delete parameter;
    }
}

const manda::MandaType *manda::MandaFunction::GetReturnType() const {
    return returnType;
}

const std::vector<manda::MandaFunctionParameter *> &manda::MandaFunction::GetParameters() const {
    return parameters;
}

void manda::MandaFunction::AddParameter(manda::MandaFunctionParameter *parameter) {
    parameters.push_back(parameter);
}
