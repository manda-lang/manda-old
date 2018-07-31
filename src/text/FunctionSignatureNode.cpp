// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "FunctionSignatureNode.h"

manda::FunctionSignatureNode::FunctionSignatureNode(const manda::ParameterListNode *parameterList,
                                                    const manda::TypeNode *returnType) {
    this->parameterList = parameterList;
    this->returnType = returnType;
}

manda::FunctionSignatureNode::~FunctionSignatureNode() {
    delete parameterList;
    delete returnType;
    parameterList = nullptr;
    returnType = nullptr;
}

const manda::ParameterListNode *manda::FunctionSignatureNode::GetParameterList() const {
    return parameterList;
}

const manda::TypeNode *manda::FunctionSignatureNode::GetReturnType() const {
    return returnType;
}

const manda::SourceSpan *manda::FunctionSignatureNode::GetSourceSpan() const {
    return parameterList->GetSourceSpan();
}
