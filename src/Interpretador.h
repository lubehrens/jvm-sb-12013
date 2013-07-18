#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Frame.h"

/** O StackFrame � a pilha de frames da JVM.
* ou seja, a Stack.
*/
typedef struct StackFrame {

}

/** O ClassDeque � uma pilha de classes j� carregadas
* � tarefa do interpretador, quando for necess�rio, buscar nesta lista se uma classe j� foi carregada
* e carreg�-la caso n�o tenha sido.
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
