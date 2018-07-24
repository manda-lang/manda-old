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
    class Analyzer : public TracksErrors
    {
    public:
        explicit Analyzer(Parser *parser);

        ~Analyzer();

        Program *VisitCompilationUnit(CompilationUnitNode *ctx);

        /**
         * Forward-declares functions, types, etc. in a module, to allow circular reference.
         * @param module
         * @param ctx
         */
        void PrecursoryVisitCompilationUnit(Module *module, CompilationUnitNode *ctx);

        Module *VisitSingleCompilationUnit(CompilationUnitNode *ctx);

        void VisitStatement(StatementNode *ctx);

    private:
        std::stack<Block *> blockStack;
        std::stack<Function *> functionStack;
        SymbolTable<Object *> *globalScope;

        void EnterFunction(Function *function);

        void ExitFunction();

        void EnterBlock(Block *block);

        void ExitBlock();
    };
}

#endif //MANDA_ANALYZER_H
