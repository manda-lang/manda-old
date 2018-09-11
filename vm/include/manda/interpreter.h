#ifndef MANDA_INTERPRETER_H
#define MANDA_INTERPRETER_H

#include "ast.h"

typedef struct _manda_interpreter manda_interpreter_t;

manda_interpreter_t *manda_interpreter_create();

void manda_interpreter_destroy(manda_interpreter_t *interpreter);

void manda_interpreter_execute(manda_interpreter_t *interpreter, manda_assembly_t *assembly);

#endif