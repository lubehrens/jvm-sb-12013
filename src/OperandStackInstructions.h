#ifndef OPERANDSTACKINSTRUCTIONS_H
#define OPERANDSTACKINSTRUCTIONS_H

int pop(Interpretador*); /*0x57*/
int pop2(Interpretador*); /*0x58*/
int dup(Interpretador*); /*0x59*/
int dup_x1(Interpretador*); /*0x5A*/
int dup_x2(Interpretador*); /*0x5B*/
int dup2(Interpretador*); /*0x5C*/
int dup2_x1(Interpretador*); /*0x5D*/
int dup2_x2(Interpretador*); /*0x5E*/
int swap(Interpretador*); /*0x5F*/

#endif
