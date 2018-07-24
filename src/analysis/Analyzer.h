// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_ANALYZER_H
#define MANDA_ANALYZER_H

#include <stack>
#include <vector>
#include "../runtime/runtime.h"
#include "../text/text.h"
#include "Object.h"
#include "Program.h"

namespace manda
{
    class Analyzer
    {
    public:
        explicit Analyzer(Parser *parser);

        ~Analyzer();

        const std::vector<Error *> &GetErrors() const;

        Program *VisitCompilationUnit(CompilationUnitNode *ctx);

        Module *VisitSingleCompilationUnit(CompilationUnitNode *ctx);

    private:
        std::vector<Error *> errors;
        SymbolTable<Object *> *globalScope;
    };
}

#endif //MANDA_ANALYZER_H
