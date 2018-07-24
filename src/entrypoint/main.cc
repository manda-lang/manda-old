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

    while ((buf = readline(">> ")) != nullptr) {
        if (strlen(buf) > 0) {
            add_history(buf);
            Lexer lexer;
            std::string line(buf);
            lexer.Scan(line, sourceUri);

            Parser parser(&lexer);
            auto *compilationUnit = parser.ParseCompilationUnit();

            // Check for errors...
            if (!parser.GetErrors().empty()) {
                for (auto *error : parser.GetErrors()) {
                    std::cout << error->GetToolString() << std::endl;
                    std::cout << error->GetSourceSpan()->Highlight(line) << std::endl;
                }

                continue;
            }
        }
    }

    return 0;
}