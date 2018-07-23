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
            delete parser.ParseProgram();

            // Check for errors...
            if (!parser.GetErrors().empty()) {
                for (auto *error : parser.GetErrors()) {
                    std::cout << error->GetToolString() << std::endl;
                    std::cout << error->GetSourceSpan()->Highlight(line) << std::endl;
                }

                continue;
            }

//            auto *object = interpreter->VisitProgram(program);
//
//            if (object == nullptr) {
//                std::cout << "null" << std::endl;
//            } else {
//                TaggedPointer::TaggedPointerType type = object->GetType();
//
//                if (type == TaggedPointer::INTEGER) {
//                    std::cout << "\033[0;36m" << std::dec << object->GetFloatData() << "\033[0m" << std::endl;
//                } else {
//                    std::cout << "Raw: 0x" << std::hex << object->GetType() << std::endl;
//                }
//            }
        }
    }

    return 0;
}