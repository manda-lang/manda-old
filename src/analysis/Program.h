// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_PROGRAM_H
#define MANDA_PROGRAM_H

#include <unordered_map>
#include <string>
#include "Module.h"

namespace manda
{
    class Program
    {
    public:
        explicit Program();

        ~Program();

        std::unordered_map<std::string, Module *> &GetModules();

        Module *GetMainModule();

        void SetMainModule(Module *module);

    private:
        std::unordered_map<std::string, Module *> modules;
        Module *mainModule;
    };
}

#endif //MANDA_PROGRAM_H
