// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_FIBER_H
#define MANDA_FIBER_H

#include <stack>
#include "SymbolTable.h"

namespace manda
{
    class Fiber
    {
    public:
        explicit Fiber();

        SymbolTable<TaggedPointer*> *GetScope() const;

        bool HasExited() const;

        void PushScope();

        void PopScope();

    private:
        SymbolTable<TaggedPointer*> *scope;
    };
}


#endif //MANDA_FIBER_H
