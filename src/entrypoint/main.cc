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
            vm->CreateFiber(program->GetMainModule()->GetImplicitFunction());

            // Load the program into the intepreter, and start JIT-ing!
            interpreter->LoadProgram(program);
            interpreter->Run();

            // Dispose of resources.
            delete program;
            delete compilationUnit;
        }
    }

    return 0;
}