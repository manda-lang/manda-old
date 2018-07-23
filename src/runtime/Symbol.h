// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SYMBOL_H
#define MANDA_SYMBOL_H

#include <string>
#include "Object.h"

namespace manda
{
    class Symbol
    {
    public:
        std::string name;
        Object *value = nullptr;
    };
}

#endif //MANDA_SYMBOL_H
