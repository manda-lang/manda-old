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

        unsigned long GetTotalVariableCount() const;

        const std::vector<std::string>& GetSsaVariables() const;

        Module *GetMainModule();

        void SetMainModule(Module *module);

        void RegisterVariable(const std::string& name);

    private:
        unsigned long totalVariableCount = 0;
        std::vector<std::string> ssaVariables;
        std::unordered_map<std::string, Module *> modules;
        Module *mainModule;
    };
}

#endif //MANDA_PROGRAM_H
