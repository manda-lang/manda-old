// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_SYMBOL_H
#define MANDA_SYMBOL_H

#include <string>
#include "TaggedPointer.h"

namespace manda
{
    template<typename T>
    class Symbol
    {
    public:
        explicit Symbol(const std::string &name, T *value);

        const std::string &GetName() const;

        T *GetValue();

    private:
        std::string name;
        T *value = nullptr;
    };
}

#endif //MANDA_SYMBOL_H
