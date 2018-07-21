// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <manda/manda.h>
#include <stdio.h>
#include <string.h>
#include <manda/struct.h>
#include "entrypoint.h"

#define MANDA_VERSION "0.0.0"

int main(int argc, const char **argv) {
    manda_options_t options;
    options.run_from_text = 1;

    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0) {
            printHelp(stdout);
            return 0;
        } else if (strcmp(arg, "--version") == 0) {
            printf("%s\n", MANDA_VERSION);
            return 0;
        } else {
            size_t filename_size = strlen(arg) + 4;
            char *filename = (char*) malloc(filename_size + 1);
            strcpy(filename, arg);
            memcpy(filename + strlen(arg), ".mnd", 4);
            filename[filename_size] = 0;
            options.input_file = fopen(filename, "r");
            options.run_from_text = 0;

            free(filename);
            if (options.input_file == NULL) {
                reportFatalError("could not open input file");
                return 1;
            }
        }
    }

    return manda_run(options);
}