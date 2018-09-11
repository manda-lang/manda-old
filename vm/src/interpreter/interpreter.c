#include <manda/manda.h>
#include <stdlib.h>

struct _manda_interpreter {
    
}

manda_interpreter_t *manda_interpreter_create() {
    return (manda_interpreter_t*) malloc(sizeof(manda_interpreter_t));
}