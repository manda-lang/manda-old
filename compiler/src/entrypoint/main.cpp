// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <antlr4-runtime/antlr4-runtime.h>
#include <iostream>
#include "../analysis/analysis.h"
#include "../analysis/MandaObject.h"
#include "../interpreter/JITInterpreter.h"

int main(int argc, const char **argv) {
    const char *filename = nullptr;

    if (argc < 2) {
        std::cerr << "fatal error: no input file" << std::endl;
        return 1;
    }

    filename = argv[1];

    manda::MandaAnalyzer analyzer;
    manda::JITInterpreter jit(analyzer);
    antlr4::ANTLRFileStream inputStream(filename);
    parser::MandaLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser::MandaParser parser(&tokens);

    auto *unit = parser.compilationUnit();

    if (parser.getNumberOfSyntaxErrors() > 0) {
        return 1;
    }

    unit->accept(&analyzer);
    jit.Run();
    return jit.GetExitCode();
}

int mainOld() {
    manda::MandaAnalyzer analyzer;
    antlr4::ANTLRInputStream inputStream("((-34 + 46) - 5) * -3");
    parser::MandaLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser::MandaParser parser(&tokens);

    antlrcpp::Any valueAny = parser.expr()->accept(&analyzer);
    auto &errors = analyzer.GetErrors();

    if (!errors.empty()) {
        for (auto *error : errors) {
            std::cerr << error->ToString() << std::endl;
        }

        return 1;
    } else {
        if (valueAny.isNull()) {
            std::cout << "Fail" << std::endl;
        } else {
            auto *value = valueAny.as<manda::MandaObjectOrType *>();

            if (value->IsType()) {
                std::cout << "Found type" << std::endl;
            } else {
                auto *obj = value->AsObject();
                std::cout << "Found object" << std::endl;
                std::cout << "Type: " << obj->GetType()->GetQualifiedName() << std::endl;

                if (obj->constantValueType != manda::MandaObject::kNone) {
                    switch (obj->constantValueType) {
                        case manda::MandaObject::kUnsigned:
                            std::cout << "Unsigned integer: " << obj->constantValue.asUnsigned << std::endl;
                            break;
                        case manda::MandaObject::kSigned:
                            std::cout << "Signed integer: " << obj->constantValue.asSigned << std::endl;
                            break;
                        case manda::MandaObject::kString:
                            std::cout << "String literal: \"" << obj->constantValue.asString << "\"" << std::endl;
                            break;
                        case manda::MandaObject::kBool:
                            std::cout << "Boolean: " << (obj->constantValue.asBool ? "true" : "false")
                                      << std::endl;
                            break;
                        default:
                            break;

                    }
                }
            }
        }
    }

    return 0;
}