#ifndef MANDA_AST_H
#define MANDA_AST_H
#include <stdint.h>

typedef enum
{
    MANDA_INSTRUCTION_ALLOC,
    MANDA_INSTRUCTION_ADD,
    MANDA_INSTRUCTION_AND,
    MANDA_INSTRUCTION_CALL,
    MANDA_INSTRUCTION_CMP,
    MANDA_INSTRUCTION_DEC,
    MANDA_INSTRUCTION_DIV,
    MANDA_INSTRUCTION_FREE,
    MANDA_INSTRUCTION_JUMP,
    MANDA_INSTRUCTION_JUMP_GREATER,
    MANDA_INSTRUCTION_JUMP_GREATER_OR_EQUAL,
    MANDA_INSTRUCTION_JUMP_LESS,
    MANDA_INSTRUCTION_JUMP_LESS_OR_EQUAL,
    MANDA_INSTRUCTION_INC,
    MANDA_INSTRUCTION_MOD,
    MANDA_INSTRUCTION_MUL,
    MANDA_INSTRUCTION_POP,
    MANDA_INSTRUCTION_PUSH,
    MANDA_INSTRUCTION_RET,
    MANDA_INSTRUCTION_SUB,
    MANDA_INSTRUCTION_XOR,
} manda_instruction_type_t;

typedef enum
{
    MANDA_ARGUMENT_UINT8,
    MANDA_ARGUMENT_INT64,
    MANDA_ARGUMENT_UINT64,
    MANDA_ARGUMENT_REGISTER,
    MANDA_ARGUMENT_REGISTER_POINTER,
    MANDA_ARGUMENT_BLOCK_POINTER
} manda_argument_type_t;

typedef struct _manda_block manda_block_t;

typedef struct
{
    manda_argument_type_t type;
    union {
        uint8_t as_uint8;
        int64_t as_int64;
        uint64_t as_uint64;
        uint8_t *as_register_index;
        manda_block_t *as_block_pointer;
    } value;
} manda_argument_t;

typedef struct
{
    manda_instruction_type_t type;
    uint8_t number_of_arguments;
    manda_argument_t *arguments;
} manda_instruction_t;

struct _manda_block
{
    const char *name;
    uint64_t number_of_instructions;
    manda_instruction_t *instructions;
};

typedef struct
{
    const char *name;
    uint64_t number_of_blocks;
    manda_block_t *blocks;
} manda_section_t;

typedef struct
{
    uint64_t number_of_globals;
    uint64_t number_of_sections;
    const char **globals;
    manda_section_t *sections;
} manda_assembly_t;

#endif