#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Frame.h"

/** O StackFrame é a pilha de frames da JVM.
* ou seja, a Stack.
*/
typedef struct StackFrame {

}

/** O ClassDeque é uma pilha de classes já carregadas
* é tarefa do interpretador, quando for necessário, buscar nesta lista se uma classe já foi carregada
* e carregá-la caso não tenha sido.
*/
typedef struct ClassDeque {

}

/** O Interpretador possui uma referencia para o Frame mais recente da pilha de frames
* e para a classe mais recente da pilha de classes
*/
typedef struct Interpretador {
    StackFrame *topFrame;
    ClassDeque *topClass;
} Interpretador;

#endif
