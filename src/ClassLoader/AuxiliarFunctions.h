#ifndef AUXILIARFUNCTIONS_H
#define AUXILIARFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassStructure.h"
#include "ClassLoader.h"

float convertU4ToFloat(u4 u4input);

/** Função que retorna a constante UTF8 de um determinado índice
*/
char getUTF8(cpInfo *cp, u2 index);


/** Função que busca uma ClassFile a partir de seu nome na lista de classes (ClassList)
*/
ClassFile getClassFileByName(ClassList* init, char* className);
#endif
