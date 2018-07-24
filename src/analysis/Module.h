// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PROGRAM_H
#define MANDA_PROGRAM_H

#include <vector>
#include "Function.h"

namespace manda
{
    class Module
    {
    public:
        explicit Module();
        ~Module();

        std::vector<Function *> &GetFunctions();

    private:
        std::vector<Function *> functions;
    };
}

#endif //MANDA_PROGRAM_H
