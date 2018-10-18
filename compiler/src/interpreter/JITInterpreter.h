// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_JITINTERPRETER_H
#define PROJECT_JITINTERPRETER_H

#include <jit/jit.h>
#include <stack>
#include "../analysis/analysis.h"

namespace manda
{
    class JITInterpreter
    {
    public:
        explicit JITInterpreter(const MandaAnalyzer &analyzer);

        ~JITInterpreter();

        jit_function_t GetMainFunction() const;

        int GetExitCode() const;

        void Run();

    private:
        const MandaAnalyzer &analyzer;
        std::stack<jit_function_t> functionStack;
        jit_function_t mainFunction;
        jit_context_t ctx;
    };
}

#endif //PROJECT_JITINTERPRETER_H
