// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAANALYZER_H
#define PROJECT_MANDAANALYZER_H

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
     * Transforms the ANTLR tree into a Manda-specific AST.
     *
     * The output AST will have all objects resolved to some type,
     * rejecting errant programs with errors.
     *
     * The output AST can in turn be processed by future passes.
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

    private:
        MandaCoreTypes *coreTypes;
        SymbolTable *currentScope;
        std::vector<MandaError *> errors;
    };
}

#endif //PROJECT_MANDAANALYZER_H
