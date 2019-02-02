// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include <sstream>
#include "lexer.h"

using namespace manda::parsing;

int main() {
    std::string line;
    std::cout << "manda> ";

    while (std::cin >> line) {
        string_scanner scanner("stdin", line);
        lexer lexer(scanner);
        lexer.scan();

        for (auto & error: lexer.errors()) {
            std::cout << "error: " << error.span << ": " << error.message << std::endl;
        }

        std::cout << "manda> ";
    }

    return 0;
}