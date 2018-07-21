// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/manda.h>
#include <stdio.h>
#include <string.h>
#include "runtime.h"
#define MANDA_VERSION "0.0.0"

int main(int argc, const char **argv) {
    manda_options_t options;

    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0) {
            printHelp(stdout);
            return 0;
        } else if (strcmp(arg, "--version") == 0) {
            printf("%s\n", MANDA_VERSION);
            return 0;
        }
    }

    return 0;
}