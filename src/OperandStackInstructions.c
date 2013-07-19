#include "OperandStackInstructions.h"

/*0x57*/
int pop(Interpretador* interpretador) {
    if (interpretador->topStackFrame->frame->topOperand->operand->type32_64 == CAT1) {
        popOperand(&(interpretador->topStackFrame->frame->topOperand));
    } else {
        printf("Erro. Topo da pilha e' do Tipo 2\n");
        exit(1);
    }
	return 0;
}

/*0x58*/
int pop2(Interpretador* interpretador) {
    if (interpretador->topStackFrame->frame->topOperand->operand->type32_64 == CAT1 &&
        interpretador->topStackFrame->frame->topOperand->nextOperand->operand->type32_64 == CAT1) {
        popOperand(&(interpretador->topStackFrame->frame->topOperand));
        popOperand(&(interpretador->topStackFrame->frame->topOperand));
    } else {
        popOperand(&(interpretador->topStackFrame->frame->topOperand));
    }
	return 0;
}

/*0x59*/
int dup(Interpretador* interpretador) {
    Operando operand;
    if (interpretador->topStackFrame->frame->topOperand->operand->type32_64 == CAT1) {
        operando = popOperand(&(interpretador->topStackFrame->frame->topOperand));
        pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando);
        pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando);
    } else {
        printf("Erro. Topo da pilha e' do Tipo 2\n");
        exit(1);
    }
	return 0;
}

/*0x5A*/
int dup_x1(Interpretador* interpretador) {
    Operando operand1, operand2;
    if (interpretador->topStackFrame->frame->topOperand->operand->type32_64 == CAT1 &&
        interpretador->topStackFrame->frame->topOperand->nextOperand->operand->type32_64 == CAT1) {
        operand1 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o valor a ser duplicado */
        operand2 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o segundo valor */
        pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand1);
        pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand2);
        pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand1);
    } else {
        printf("Erro. Topo da pilha e' do Tipo 2\n");
        exit(1);
    }
	return 0;
}

/*0x5B*/
/** Duplica o valor do topo da pilha e insere o valor duplicado dois slots abaixo, se valor2 for do Tipo 2.
* valor1, valor2 -> valor2, valor1, valor2
* Duplica o valor do topo da pilha e insere o valor duplicado três slots abaixo, se valor2 e valor3 forem do Tipo 1.
* valor1, valor2, valor3 -> valor3, valor1, valor2, valor3
*/
int dup_x2(Interpretador* interpretador) {
    Operando operand1, operand2, operand3;
    if (interpretador->topStackFrame->frame->topOperand->operand->type32_64 == CAT1) {
        if (interpretador->topStackFrame->frame->topOperand->nextOperand->operand->type32_64 == CAT2) { /* dois slots abaixo */
            operand1 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o valor a ser duplicado */
            operand2 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o segundo valor (Tipo 2) */
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando1);
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando2);
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando1);
        } else if (interpretador->topStackFrame->frame->topOperand->nextOperand->nextOperand->operand->type32_64 == CAT1) {
            operand1 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o valor a ser duplicado */
            operand2 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o segundo valor (Tipo 1) */
            operand3 = popOperand(&(interpretador->topStackFrame->frame->topOperand)); /* pega o terceiro valor (Tipo 1) */
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando1);
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando2);
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando3);
            pushOperand(&(interpretador->topStackFrame->frame->topOperand), operando1);
        } else {
            printf("Erro. O terceiro valor e' do Tipo 2\n");
            exit(1);
        }
    } else {
        printf("Erro. O primeiro valor e' do Tipo 2\n");
        exit(1);
    }
	return 0;
}

/*0x5C*/
int dup2(Interpretador* interpretador) {
}

/*0x5D*/
int dup2_x1(Interpretador* interpretador) {
}

/*0x5E*/
int dup2_x2(Interpretador* interpretador) {
}

/*0x5F*/
int swap(Interpretador* interpretador) {
}

#endif
