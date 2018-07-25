// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <readline/readline.h>
#include <fstream>
#include <iostream>
#include "../manda_src.h"

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

    auto *vm = new VM;
    auto *interpreter = new Interpreter(vm);
    std::string sourceUri("stdin");
    char *buf = nullptr;

    while ((buf = readline(">> ")) != nullptr) {
        if (strlen(buf) > 0) {
            add_history(buf);
            Lexer lexer;
            std::string line(buf);
            lexer.Scan(line, sourceUri);
            Parser parser(&lexer);
            auto *compilationUnit = parser.ParseCompilationUnit();
            Analyzer analyzer(&parser, true);
            auto *program = analyzer.VisitCompilationUnit(compilationUnit);

            // Check for errors...
            if (!analyzer.GetErrors().empty()) {
                for (auto *error : analyzer.GetErrors()) {
                    std::cout << error->GetToolString() << std::endl;
                    std::cout << error->GetSourceSpan()->Highlight(line) << std::endl;
                }

                delete program;
                delete compilationUnit;
                continue;
            }

            // Dispose of existing fibers.
            vm->ClearFibers();

            // Create a new fiber to run our code.
            auto *fiber = vm->CreateFiber(program->GetMainModule()->GetImplicitFunction());

            // Load the program into the intepreter, and start JIT-ing!
            interpreter->LoadProgram(program);
            interpreter->Run();

            auto result = fiber->GetResult();

            if (nanbox_is_undefined_or_null(result)) {
                std::cout << "\033[0;37m" << "undefined";
            } else if (nanbox_is_empty(result)) {
                std::cout << "\033[0;37m" << "(empty)";
            } else if (nanbox_is_boolean(result)) {
                std::cout << "\033[0;37m" << "(boolean)";
            } else if (nanbox_is_deleted(result)) {
                std::cout << "\033[0;37m" << "(deleted)";
            } else if (nanbox_is_aux(result)) {
                std::cout << "\033[0;37m" << "(aux)";
            } else if (nanbox_is_pointer(result)) {
                std::cout << "\033[0;37m" << "(ptr)";
            } else if (nanbox_is_number(result)) {
                std::cout << "\033[0;36m";

                if (nanbox_is_double(result)) {
                    std::cout << nanbox_to_double(result);
                } else {
                    std::cout << nanbox_to_int(result);
                }
            } else {
                assert(false);
            }

            // Reset ANSI
            std::cout << "\033[0m" << std::endl;

            // Dispose of resources.
            delete program;
            delete compilationUnit;
        }
    }

    return 0;
}