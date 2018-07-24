// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_VM_H
#define MANDA_VM_H

#include <vector>
#include "Fiber.h"
#include "Memory.h"

namespace manda
{
    class Function;

    class VM
    {
    public:
        Fiber *CreateFiber(Function *function);

        const std::vector<Fiber*>& GetFibers() const;

        void ClearFibers();
    private:
        std::vector<Fiber *> fibers;
        Memory memory;
    };
}


#endif //MANDA_VM_H
