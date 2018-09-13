#ifndef MANDA_VM_H
#define MANDA_VM_H

#include "ast.h"

#define MANDA_RESULT_OK 0
#define MANDA_RESULT_ERROR 1

typedef struct _manda_vm manda_vm_t;

typedef struct _manda_thread manda_thread_t;

manda_vm_t *manda_vm_create();

void manda_vm_destroy(manda_vm_t *vm);

const char *manda_vm_get_error(manda_vm_t *vm);

manda_thread_t manda_vm_spawn_thread(manda_vm_t *vm);

int manda_thread_compile_entry_point(manda_thread_t *thread, manda_assembly_t *assembly, manda_block_t *entry_point);

#endif