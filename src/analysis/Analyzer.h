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
        explicit Analyzer(bool isRepl = false);

        ~Analyzer();

        void LoadParser(Parser *parser);

        Program *VisitCompilationUnit(const CompilationUnitNode *ctx);

        /**
         * Forward-declares functions, types, etc. in a module, to allow circular reference.
         * @param module
         * @param ctx
         */
        void PrecursoryVisitCompilationUnit(Module *module, const CompilationUnitNode *ctx);

        Module *VisitSingleCompilationUnit(const CompilationUnitNode *ctx);

        void VisitStatement(const StatementNode *ctx);

        void VisitExpressionStatement(const ExpressionStatementNode *ctx);

        void VisitVariableDeclarationStatement(const VariableDeclarationStatementNode *ctx);

        Object *VisitExpression(const ExpressionNode *ctx);

        Object *VisitBinaryExpression(const BinaryExpressionNode *ctx);

        Object *VisitNumberLiteral(const NumberLiteralNode *ctx);

        Object *VisitSimpleIdentifier(const SimpleIdentifierNode *ctx);

    private:
        std::stack<Block *> blockStack;
        std::stack<Function *> functionStack;
        std::stack<Program *> programStack;
        bool isRepl = false;
        Module *coreModule = nullptr;
        SymbolTable<Object *> *globalScope;

        const Type *GetCoreType(const char *name);

        void CreateCoreModule();

        void EnterFunction(Function *function);

        void ExitFunction();

        void EnterBlock(Block *block);

        void ExitBlock();
    };
}

#endif //MANDA_ANALYZER_H
