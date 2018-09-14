// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <antlr4-runtime/antlr4-runtime.h>
#include <iostream>
#include "../analysis/analysis.h"

int main() {
    manda::MandaAnalyzer analyzer;
    antlr4::ANTLRInputStream inputStream("x");
    parser::MandaLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser::MandaParser parser(&tokens);

    antlrcpp::Any valueAny = parser.expr()->accept(&analyzer);
    auto &errors = analyzer.GetErrors();

    if (errors.empty()) {
        for (auto *error : errors) {
            std::cerr << error->ToString() << std::endl;
        }

        return 1;
    }
    else {
        if (valueAny.isNull()) {
            std::cout << "Fail" << std::endl;
        } else {
            auto *value = valueAny.as<manda::MandaObjectOrType *>();

            if (value->IsType()) {
                std::cout << "Found type" << std::endl;
            } else {
                std::cout << "Found object" << std::endl;
            }
        }
    }

    return 0;
}