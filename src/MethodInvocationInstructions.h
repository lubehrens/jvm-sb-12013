#ifndef METHODINVOCATIONINSTRUCTIONS_H
#define METHODINVOCATIONINSTRUCTIONS_H

int invokevirtual(Interpretador*); /*0xB6*/
int invokespecial(Interpretador*); /*0xB7*/
int invokestatic(Interpretador*); /*0xB8*/
int invokeinterface(Interpretador*); /*0xB9*/

#endif
