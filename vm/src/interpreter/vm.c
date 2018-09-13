#include <manda/manda.h>
#include <stdlib.h>

struct _manda_vm {
    
};

manda_vm_t *manda_vm_create() {
    return (manda_vm_t*) malloc(sizeof(manda_vm_t));
}