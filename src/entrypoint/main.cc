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

            for (auto *token : lexer.GetTokens()) {
                std::cout << token->GetSourceSpan()->GetToolString() << std::endl;
                std::cout << token->GetSourceSpan()->Highlight(line) << std::endl;
            }

//            Parser parser(&lexer);
//            auto *program = parser.ParseProgram();
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