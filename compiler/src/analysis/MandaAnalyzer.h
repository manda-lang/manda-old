// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAANALYZER_H
#define PROJECT_MANDAANALYZER_H

#include <antlr4-runtime/antlr4-runtime.h>
#include <vector>
#include "../parser/parser.h"
#include "MandaCoreTypes.h"
#include "MandaError.h"
#include "SymbolTable.h"

using antlrcpp::Any;
using parser::MandaBaseVisitor;
using parser::MandaParser;

namespace manda
{
    /**
     * Transforms the ANTLR tree into a control-flow graph; also performs static type-checking.
     */
    class MandaAnalyzer
    {
    public:
        MandaAnalyzer();

        std::vector<MandaError> errors;

        const MandaCoreTypes &coreTypes;

        const MandaCoreTypes &GetCoreTypes() const;

        MandaParser::CompilationUnitContext *GetCompilationUnit() const;

        MandaObjectOrType &visitExpr(MandaParser::ExprContext *ctx);

        MandaObject &visitTrueExpr(MandaParser::TrueExprContext *ctx);

        MandaObject &visitFalseExpr(MandaParser::FalseExprContext *ctx);

        MandaObject &visitIntegerExpr(MandaParser::IntegerExprContext *ctx);

        MandaObject &visitHexExpr(MandaParser::HexExprContext *ctx);

        MandaObjectOrType &visitParenExpr(MandaParser::ParenExprContext *ctx);

        MandaObject &visitFloatExpr(MandaParser::FloatExprContext *ctx);

        MandaObjectOrType &visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx);

        void visitExprStmt(MandaParser::ExprStmtContext *ctx);

        MandaObjectOrType &resolveBinary(antlr4::ParserRuleContext *ctx, MandaParser::ExprContext *leftCtx,
                                         MandaParser::ExprContext *rightCtx, const std::string &op);

        MandaObjectOrType &visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *ctx);

        MandaObjectOrType &visitAddOrSubExpr(MandaParser::AddOrSubExprContext *ctx);

        MandaObjectOrType &visitBoolAndOrExpr(MandaParser::BoolAndOrExprContext *ctx);

        void visitReturnStmt(MandaParser::ReturnStmtContext *ctx);

        void visitCompilationUnit(MandaParser::CompilationUnitContext *ctx);

        MandaObjectOrType &visitBoolEqOrNeqExpr(MandaParser::BoolEqOrNeqExprContext *ctx);

    private:
        MandaParser::CompilationUnitContext *unit;
        SymbolTable currentScope;
    };
}

#endif //PROJECT_MANDAANALYZER_H
