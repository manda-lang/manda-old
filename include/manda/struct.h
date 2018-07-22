// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_STRUCT_H
#define MANDA_STRUCT_H

#include <stdio.h>

/**
 * Options used to configure a Manda runtime.
 */
typedef struct
{
    /**
     * The file stream to execute text from.
     */
    FILE *input_file;

    /**
     * Specifies whether Manda should execute from an input_file, or from text.
     */
    char run_from_text;

    /**
     * The string to execute text from.
     */
    const char* text;

    const char* source_uri;
} manda_options_t;

#endif //MANDA_STRUCT_H
