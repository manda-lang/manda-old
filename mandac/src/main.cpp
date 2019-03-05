// Copyright (c) 2019, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by a
// license that can be found in the LICENSE file.
#include <iostream>
#include "scanner.hpp"

int main()
{
    mandac::Scanner scanner;
    scanner.scan("(a");

    for (auto &token : scanner.getTokens()) {
        std::cout << token.line << ":" << token.column << ": " << token.text << std::endl;
    }

    return 0;
}