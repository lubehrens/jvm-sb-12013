#ifndef METHODINVOCATIONINSTRUCTIONS_H
#define METHODINVOCATIONINSTRUCTIONS_H

#include "ClassLoader/ClassStructure.h"
#include "ClassLoader/AuxiliarFunctions.h"
#include "InstructionManager.h"
#include "Interpretador.h"
#include "Frame.h"

int invokevirtual(Interpretador*); /*0xB6*/
int invokespecial(Interpretador*); /*0xB7*/
int invokestatic(Interpretador*); /*0xB8*/
int invokeinterface(Interpretador*); /*0xB9*/

#endif
