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
    class Function;

    class Fiber
    {
    public:
        explicit Fiber(Function *function);

        SymbolTable<double> *GetScope() const;

        const Function *GetFunction() const;

        bool IsWaiting() const;

        bool HasExited() const;

        void Exit();

        void WaitFor(void * task);

        void Resume(double result);

        void PushScope();

        void PopScope();

    private:
        bool exited = false;
        bool waiting = false;
        Function *function;
        SymbolTable<double> *scope;
    };
}


#endif //MANDA_FIBER_H
