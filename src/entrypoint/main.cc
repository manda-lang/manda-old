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
//    TaggedPointer pp;
//    pp.SetFloatData(56.3);
//    pp.SetType(TaggedPointer::POINTER);
//    std::cout << pp.GetType() << std::endl;
//    std::cout << "0b" << std::hex << pp.ToBitset() << std::endl;
//
//    TaggedPointer qq(pp.GetRawDouble());
//    std::cout << qq.GetType() << std::endl;
//    std::cout << std::dec << qq.GetFloatData() << std::endl;

    std::string sourceUri("stdin");
    char *buf = nullptr;
    auto *vm = new VM;
    auto *fiber = vm->CreateFiber();

    while ((buf = readline(">> ")) != nullptr) {
        if (strlen(buf) > 0) {
            add_history(buf);
            Lexer lexer;
            std::string line(buf);
            lexer.Scan(line, sourceUri);

            Parser parser(&lexer);
            auto *program = parser.ParseCompilationUnit();

            // Check for errors...
            if (!parser.GetErrors().empty()) {
                for (auto *error : parser.GetErrors()) {
                    std::cout << error->GetToolString() << std::endl;
                    std::cout << error->GetSourceSpan()->Highlight(line) << std::endl;
                }


                continue;
            }

            auto *interpreter = new Interpreter(vm, fiber);
            auto *object = interpreter->VisitCompilationUnit(program);

            if (object == nullptr) {
                std::cout << "null" << std::endl;
            } else {
                TaggedPointer::TaggedPointerType type = object->GetType();

                if (type == TaggedPointer::ACTUAL_NUMBER) {
                    std::cout << "\033[0;36m0b" << object->ToBitset() << "\033[0m" << std::endl;
                    std::cout << "\033[0;36m0x" << std::hex << object->GetRawUlong() << "\033[0m" << std::endl;
                    std::cout << "\033[0;36mdec: " << std::dec << object->GetRawUlong() << "\033[0m" << std::endl;
                    std::cout << "\033[0;36mdbl: " << std::dec << object->GetRawDouble() << "\033[0m" << std::endl;
                    std::cout << "\033[0;36mdata: " << std::dec << object->GetData() << "\033[0m" << std::endl;
                    std::cout << "\033[0;36m" << std::dec << object->GetFloatData() << "\033[0m" << std::endl;
                } else {
                    std::cout << "Raw: 0x" << std::hex << object->GetType() << std::endl;
                }
            }

            delete interpreter;
        }
    }

    return 0;
}