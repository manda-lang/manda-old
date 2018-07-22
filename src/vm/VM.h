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
    class VM
    {
    public:
        std::vector<Fiber *> fibers;
        Memory memory;

        Fiber* createFiber();
    };
}


#endif //MANDA_VM_H
