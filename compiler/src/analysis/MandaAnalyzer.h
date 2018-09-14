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
    class MandaAnalyzer : public MandaBaseVisitor
    {
    public:
        MandaAnalyzer();

        const std::vector<MandaError *> &GetErrors() const;

        Any visitIntegerExpr(MandaParser::IntegerExprContext *ctx) override;

        Any visitHexExpr(MandaParser::HexExprContext *ctx) override;

        Any visitParenExpr(MandaParser::ParenExprContext *ctx) override;

        Any visitFloatExpr(MandaParser::FloatExprContext *ctx) override;

        Any visitIdentifierExpr(MandaParser::IdentifierExprContext *ctx) override;

        Any visitExprStmt(MandaParser::ExprStmtContext *ctx) override;

        Any resolveBinary(antlr4::ParserRuleContext *ctx, MandaParser::ExprContext *leftCtx,
                                  MandaParser::ExprContext *rightCtx, const std::string &op);

        Any visitMulDivOrModExpr(MandaParser::MulDivOrModExprContext *ctx) override;

        Any visitAddOrSubExpr(MandaParser::AddOrSubExprContext *ctx) override;

        Any visitReturnStmt(MandaParser::ReturnStmtContext *ctx) override;

    private:
        MandaCoreTypes *coreTypes;
        SymbolTable *currentScope;
        std::vector<MandaError *> errors;
    };
}

#endif //PROJECT_MANDAANALYZER_H
