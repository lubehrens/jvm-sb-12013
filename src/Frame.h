#ifndef FRAME_H
#define FRAME_H
#define CAT1 1
#define CAT2 2

/** Se��o de ambiente de execu��o.
* Cont�m um ponteiro para a classe � qual o m�todo pertence,
* um ponteiro para o opcode da instru��o sendo lida
* e um program counter, que indica o endere�o da instru��o sendo lida
*/
typedef struct ExecEnvirSection {
    cpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
} ExecEnvirSection;

typedef struct Operand {
    int type32_64; /*1: operandos do tipo 1 | 2: operandos do tipo 2*/
    union OperandType {
        int intType;
        long long longType;
        float floatType;
        double doubleType;
        void* referenceType;
    } operandType;
} Operand;

/** Pilha de operandos.
* Cont�m o tipo do operando, definido por uma union, um int que indica se � do tipo 1 ou 2
* e um ponteiro para o pr�ximo operando da pilha.
*/
typedef struct OperandStack {
    Operand operand;
    struct OperandStack *nextOperand;
} OperandStack;

/** O Frame � composto de um array de vari�veis locais, uma pilha de operandos
* e um ambiente de execu��o dos m�todos
*/
typedef struct Frame {
    int *localVarArray;    // array de variaveis locais de 32 bits por slot
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame;

#endif
