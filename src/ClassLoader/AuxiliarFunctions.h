#ifndef AUXILIARFUNCTIONS_H
#define AUXILIARFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassStructure.h"
#include "ClassLoader.h"
#include "Frame.h"

float convertU4ToFloat(u4 u4input);

/** Fun��o que retorna a constante UTF8 de um determinado �ndice
*/
u1* getUTF8(CpInfo *cp, u2 index);

/** Fun��o que retorna o numero de arugmentos de um m�todo baseando-se no seu descritor
*/
int methodArgsCount(char* descriptor);

/** Fun��o que busca uma ClassFile a partir de seu nome na lista de classes (ClassList)
*/
ClassFile* getClassFileByName(ClassList* init, char* className);

/** Fun��o que busca um m�todo a partir de seu nome e descritor. Retorna NULL se n�o existir
*/
MethodInfo* getMethod(ClassFile, char* methodName, char* methodDescriptor);

char* getClassName(char *classpath);

ClassFile* isLoaded(Interpretador*, char*);

void insertStaticFieldValue(ClassList*, char*, char*, Operand);

// Fun��o que preenche o array de fields do objeto com os fields de todas
// as classes ligadas a ele (classe + super classes) e inicializa o valor com 0
void fieldsInit(Interpretador, ClassFile, Field*);

Array* createMultiArray(int, int*);

#endif
