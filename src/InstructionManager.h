#ifndef INSTRUCTION_MANAGER_H
#define INSTRUCTION_MANAGER_H

#define ILOAD 0x15
#define LLOAD 0x16
#define FLOAD 0x17
#define DLOAD 0x18
#define ALOAD 0x19
#define ISTORE 0x36
#define LSTORE 0x37
#define FSTORE 0x38
#define DSTORE 0x39
#define ASTORE 0x3A
#define RET 0xA9
#define IINC 0x84

/** Variavel global que indica se a instrução wide foi chamada */
int isWide = 0;

/** Ponteiro para funções de execução de instruções */
int (*InstructionArray[])(Interpretador*);

/** Unions que permitem acesso à mesma região de memória com tipos diferentes
*   sem efetuar conversão de valores, apenas lendo o dado de maneira distinta.
*/
typedef union FloatToInt {
    float f;
    int i;
} FloatToInt;

typedef union DoubleToInt {
    double d;
    int pairedInt[2];
} DoubleToInt;

typedef union LongToInt {
    long long l;
    int pairedInt[2];
} LongToInt;

typedef union VoidToInt {
    void* voidAddress;
    int intAddress;
} VoidToInt;

#endif
