#ifndef OPERANDSTACKINSTRUCTIONS_H
#define OPERANDSTACKINSTRUCTIONS_H

/** Retira o primeiro operando da pilha de operandos.
*/
int pop(Interpretador*); /*0x57*/

/** Retira dois operandos da pilha de operandos, se eles forem do Tipo 1.
* Retira o primeiro operando da pilha de operandos se ele for do Tipo 2.
*/
int pop2(Interpretador*); /*0x58*/

/** Duplica o valor do topo da pilha e insere o valor duplicado na pilha.
* valor -> valor, valor
* Só pode ser usada para operandos do Tipo 1.
*/
int dup(Interpretador*); /*0x59*/

/** Duplica o valor do topo da pilha e insere o valor duplicado dois slots abaixo na pilha.
* valor1, valor2 -> valor2, valor1, valor2
* Só pode ser usada para operandos do Tipo 1.
*/
int dup_x1(Interpretador*); /*0x5A*/

/** Duplica o valor do topo da pilha e insere o valor duplicado dois slots abaixo, se valor2 for do Tipo 2.
* valor1, valor2 -> valor2, valor1, valor2
* Duplica o valor do topo da pilha e insere o valor duplicado três slots abaixo, se valor2 e valor3 forem do Tipo 1.
* valor1, valor2, valor3 -> valor3, valor1, valor2, valor3
*/

/**
*/
int dup2(Interpretador*); /*0x5C*/

/**
*/
int dup2_x1(Interpretador*); /*0x5D*/

/**
*/
int dup2_x2(Interpretador*); /*0x5E*/

/**
*/
int swap(Interpretador*); /*0x5F*/

#endif
