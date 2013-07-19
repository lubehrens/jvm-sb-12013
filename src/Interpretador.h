#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Frame.h"

/** O StackFrame é a pilha de frames da JVM.
* ou seja, a Stack.
*/
typedef struct StackFrame {
    Frame frame;
    struct StackFrame *nextFrame;
} StackFrame;

/** Estrutura que define um campo.
* Contém o nome, o descritor e o tipo do field.
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
* Contém a quantidade de campos e os campos.
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

/** O ClassList é uma lista de classes já carregadas.
* É tarefa do interpretador, quando for necessário, buscar nesta lista se uma classe já foi carregada
* e carregá-la caso não tenha sido.
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
