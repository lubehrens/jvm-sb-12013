#ifndef FRAME_H
#define FRAME_H
#define CAT1 1
#define CAT2 2

/** Seção de variáveis locais que é na verdade uma pilha de variaveis locais
*/
typedef struct LocalVarStack {

} LocalVarStack;

/** Seção de ambiente de execução.
* Contém um ponteiro para a classe à qual o método pertence,
* um ponteiro para o opcode da instrução sendo lida
* e um program counter, que indica o endereço da instrução sendo lida
*/
typedef struct ExecEnvirSection {
    cpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
} ExecEnvirSection;

/** Pilha de operandos.
* Contém o tipo do operando, definido por uma union, um int que indica se é do tipo 1 ou 2
* e um ponteiro para o próximo operando da pilha.
*/
typedef struct OperandStack {
    int type32_64; /*1: operandos do tipo 1 | 2: operandos do tipo 2*/
    struct OperandStack *nextOperand;
    union OperandType {
        int intType;
        long long longType;
        float floatType;
        double doubleType;
        void* referenceType;
    } operandType;
} OperandStack;

/** O Frame é composto de uma lista de variáveis locais, uma pilha de operandos
* e um ambiente de execução dos métodos
*/
typedef struct Frame {
    LocalVarStack *topVar;
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame;

#endif
