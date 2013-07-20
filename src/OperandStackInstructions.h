#ifndef OPERANDSTACKINSTRUCTIONS_H
#define OPERANDSTACKINSTRUCTIONS_H

/** Retira o primeiro operando da pilha de operandos.
*/
int pop(Interpretador*); /*0x57*/

/** Retira os dois primeiros operandos da pilha de operandos, se eles forem do Tipo 1.
* Retira o primeiro operando da pilha de operandos se ele for do Tipo 2.
*/
int pop2(Interpretador*); /*0x58*/

/** Duplica o primeiro valor da pilha.
* valor -> valor, valor
* S� pode ser usada para operandos do Tipo 1.
*/
int dup(Interpretador*); /*0x59*/

/** Duplica o primeiro valor da pilha e o insere dois slots abaixo.
* valor2, valor1 -> valor1, valor2, valor1
* S� pode ser usada para operandos do Tipo 1.
*/
int dup_x1(Interpretador*); /*0x5A*/

/** Caso 1: valor1 � do Tipo 2.
* Duplica oprimeiro valor da pilha e o insere dois slots abaixo.
* valor2, valor1 -> valor1, valor2, valor1
* Caso 2: valor1 e valor2 s�o do Tipo 1.
* Duplica o primeiro valor da pilha e o insere tr�s slots abaixo.
* valor3, valor2, valor1 -> valor1, valor3, valor2, valor1
*/
int dup_x2(Interpretador*); /*0x5B*/

/** Caso 1: valor � do Tipo 2.
* Duplica o primeiro valor da pilha.
* valor -> valor, valor
* Caso 2: valor1 e valor2 s�o do Tipo 1.
* Duplica os dois primeiros valores da pilha.
* valor2, valor1 -> valor2, valor1, valor2, valor1
*/
int dup2(Interpretador*); /*0x5C*/

/** Caso 1: valor1 � do Tipo 2.
* Duplica o primeiro valor da pilha e o insere dois slots abaixo.
* valor2, valor1 -> valor1, valor2, valor1
* Caso 2: valor1 e valor2 s�o do Tipo 1.
* Duplica os dois primeiros valores da pilha e os insere tr�s slots abaixo.
* valor3, valor2, valor1 -> valor2, valor1, valor3, valor2, valor1
*/
int dup2_x1(Interpretador*); /*0x5D*/

/** Caso 1: valor1, valor2, valor3 e valor4 s�o do Tipo 1.
* Duplica os dois primeiros valores da pilha e os insere quatro slots abaixo.
* valor4, valor3, valor2, valor1 -> valor2, valor1, valor4, valor3, valor2, valor1
* Caso 2: valor1 � do Tipo 2, valor2 e valor3 s�o do Tipo 1.
* Duplica o primeiro valor da pilha e o insere tr�s slots abaixo.
* valor3, valor2, valor1 -> valor1, valor3, valor2, valor1
* Caso 3: valor1 e valor2 s�o do Tipo 1, valor3 � do Tipo 2.
* Duplica os dois primeiros valores da pilha e os insere dois slots abaixo.
* valor3, valor2, valor1 -> valor2, valor1, valor3, valor2, valor1
* Caso 4: valor1 e valor2 s�o do Tipo 2.
* Duplica o primeiro valor da pilha e o insere dois slots abaixo.
* valor2, valor1 -> valor1, valor2, valor1
*/
int dup2_x2(Interpretador*); /*0x5E*/

/** Troca o primeiro valor da pilha pelo segundo valor.
* valor2, valor1 -> valor1, valor2
*/
int _swap(Interpretador*); /*0x5F*/

#endif
