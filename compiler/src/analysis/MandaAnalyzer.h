// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MANDAANALYZER_H
#define PROJECT_MANDAANALYZER_H

#include "../parser/parser.h"

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

    };
}

#endif //PROJECT_MANDAANALYZER_H
