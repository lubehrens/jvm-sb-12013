#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Frame.h"
#include "ClassLoader/AuxiliarFunctions.h"

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

/** Fun��o de inicializa��o da lista de classes carregadas */
void initClassList(ClassList**);
/** Fun��o que inicializa o vetor de campos est�ticos de um elemento ClassList */
void initStaticFields(ClassList*, ClassFile);
/** Fun��o de inser��o de elemento na lista de classes carregadas */
void appendClassList(ClassList**, ClassFile);
/** Fun��o que carrega a classe em mem�ria, se ela n�o estiver j� carregada */
ClassFile* loadClass(Interpretador*, char*);
/** Fun��o de inicializa��o da main, passando o que foi lido da linha de comando */
void mainInit(char* className, Interpretador* interpretador, int, char**);
/** Fun��o de inicializa��o dos demais m�todos */
void methodInit(char*, char*, char*, Interpretador*, int);
/** Fun��o de execu��o de um m�todo */
void methodExec(Interpretador*);

#endif
