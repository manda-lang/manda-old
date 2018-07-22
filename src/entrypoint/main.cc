// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <readline/readline.h>
#include <antlr4-runtime.h>
#include <fstream>
#include <iostream>
#include "../manda_text/manda_text.h"
#include "../vm/Object.h"
#include "../vm/Interpreter.h"

using namespace antlr4;
using namespace manda;
using namespace manda_text;

int main() {
    VM vm;
    auto *fiber = vm.createFiber();
    Interpreter interpreter(&vm, fiber);

    char *line;
    while ((line = readline(">> ")) != nullptr) {
        if (strlen(line) > 0) {
            add_history(line);
        }

        ANTLRInputStream inputStream(line);
        MandaLexer lexer(&inputStream);
        CommonTokenStream tokens(&lexer);
        MandaParser parser(&tokens);
        parser.setBuildParseTree(true);
        auto *program = parser.program();
        auto result = interpreter.visitProgram(program);

        if (result.isNull()) {
            std::cout << "<null>" << std::endl;
        } else if (result.is<Object *>()) {
            std::cout << result.as<Object *>()->ansiColor();
            result.as<Object *>()->toString(std::cout);
            std::cout << std::endl;
        } else {
            std::cout << "<unknown>" << std::endl;
        }

        std::cout << "\33[0m";
    }
}