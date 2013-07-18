#ifndef FRAME_H
#define FRAME_H

/** Se��o de vari�veis locais que � na verdade uma pilha de variaveis locais
*/
typedef struct LocalVarStack {

} LocalVarStack

/** Se��o de ambiente de execu��o.
* contem um ponteiro para a classe a quem o m�todo pertence,
* um ponteiro para o opcode da instru��o sendo lida
* um program counter que indica o endere�o da instru��o sendo lida
*/
typedef struct ExecEnvirSection {
    cpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
}

/** O Frame � composto de uma pilha de vari�veis locais, uma pilha de operandos
* e um ambiente de execu��o dos m�todos
*/
typedef struct Frame {
    LocalVarStack *topVar;
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame

#endif
