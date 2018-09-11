#ifndef MANDA_VM_H
#define MANDA_VM_H

#include "ast.h"

typedef struct _manda_vm manda_vm_t;

manda_vm_t *manda_vm_create();

void manda_vm_destroy(manda_vm_t *vm);

void manda_vm_execute(manda_vm_t *vm, manda_assembly_t *assembly);

#endif