// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "parsing.h"

int main() {
    std::string line;
    std::cout << "manda> ";

    while (std::cin >> line) {
        manda::parse_ast(line);
        std::cout << "manda> ";
    }

    return 0;
}