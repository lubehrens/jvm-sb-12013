#ifndef FRAME_H
#define FRAME_H

/** Seção de variáveis locais que é na verdade uma pilha de variaveis locais
*/
typedef struct LocalVarStack {

} LocalVarStack

/** Seção de ambiente de execução.
* contem um ponteiro para a classe a quem o método pertence,
* um ponteiro para o opcode da instrução sendo lida
* um program counter que indica o endereço da instrução sendo lida
*/
typedef struct ExecEnvirSection {
    cpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
}

/** O Frame é composto de uma pilha de variáveis locais, uma pilha de operandos
* e um ambiente de execução dos métodos
*/
typedef struct Frame {
    LocalVarStack *topVar;
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame

#endif
