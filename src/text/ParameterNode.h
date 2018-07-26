// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PARAMETERNODE_H
#define MANDA_PARAMETERNODE_H

#include <string>
#include "AstNode.h"
#include "ExpressionNode.h"

namespace manda
{
    class ParameterNode : public AstNode
    {
    private:
        std::string name;
        ExpressionNode *defaultValue;
    };
}

#endif //MANDA_PARAMETERNODE_H
