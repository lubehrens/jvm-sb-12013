#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Frame.h"

/** O StackFrame � a pilha de frames da JVM.
* ou seja, a Stack.
*/
typedef struct StackFrame {
    Frame frame;
    struct StackFrame *nextFrame;
} StackFrame;

/** Estrutura que define um campo.
* Cont�m o nome, o descritor e o tipo do field.
*/
typedef struct Field {
	char* name;
	char* descriptor;
    union FieldType {
        int intType;
        short shortType;
        float floatType;
        long long longType;
        double doubleType;
        char charType;
        void* referenceType;
    } fieldType;
} Field;

/** Estrutura que define um objeto.
* Cont�m a quantidade de campos e os campos.
*/
typedef struct Object {
	int fieldsCount;
	Field* fields;
} Object;

/** Estrutura que define uma lista de objetos
*/
typedef struct ObjectsList {
	Object object;
	struct ObjectList *nextObject;
} ObjectList;

/** O ClassList � uma lista de classes j� carregadas.
* � tarefa do interpretador, quando for necess�rio, buscar nesta lista se uma classe j� foi carregada
* e carreg�-la caso n�o tenha sido.
*/
typedef struct ClassList {
    ClassFile *classFile;
    int staticFieldsCount;
    Field *staticFields;
    ObjectsList *objectsList;
    struct ClassList *nextClass;
} ClassList;

/** O Interpretador possui uma referencia para o Frame mais recente da pilha de frames
* e para a classe mais recente da lista de classes
*/
typedef struct Interpretador {
    StackFrame *topStackFrame;
    ClassList *initClass;
} Interpretador;

#endif
