#ifndef RETURNINSTRUCTIONS_H
#define RETURNINSTRUCTIONS_H

int ireturn(Interpretador*); /*0xAC*/
int lreturn(Interpretador*); /*0xAD*/
int freturn(Interpretador*); /*0xAE*/
int dreturn(Interpretador*); /*0xAF*/
int areturn(Interpretador*); /*0xB0*/
int return(Interpretador*);  /*0xB1*/

#endif

