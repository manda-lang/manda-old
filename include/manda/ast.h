// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef MANDA_AST_H
#define MANDA_AST_H

typedef enum
{
    MANDA_DIRECTIVE_IMPORT,
    MANDA_DIRECTIVE_WITH,
} manda_directive_type;

typedef struct
{
    manda_directive_type type;
}
        manda_directive_t;

typedef struct
{

}
        manda_program_t;

#endif //MANDA_AST_H
