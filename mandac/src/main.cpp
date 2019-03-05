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
    mandac::Scanner scanner("stdin");
    scanner.scan(stdin);

    for (auto &token : scanner.getTokens()) {
        std::cout << token.sourceUrl << ":" << token.line << ":" << token.column << ":" << token.text << "=>" << token.type << std::endl;
    }

    return 0;
}