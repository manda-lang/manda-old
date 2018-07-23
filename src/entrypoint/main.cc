// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <readline/readline.h>
#include <fstream>
#include <iostream>
#include "../src.h"

using namespace manda;

int main() {
    std::string sourceUri("<stdin>");
    char *buf = nullptr;
    auto *vm = new VM;
    auto *fiber = vm->CreateFiber();
    auto *interpreter = new Interpreter(vm, fiber);

    while ((buf = readline(">> ")) != nullptr) {
        if (strlen(buf) > 0) {
            add_history(buf);
            Lexer lexer;
            std::string line(buf);
            lexer.Scan(line, sourceUri);
            Parser parser(&lexer);
            auto *program = parser.ParseProgram();
            auto *object = interpreter->VisitProgram(program);

            if (object == nullptr) {
                std::cout << "null" << std::endl;
            } else {
                std::cout << object->GetFloatData() << std::endl;
            }
        }
    }

    return 0;
}