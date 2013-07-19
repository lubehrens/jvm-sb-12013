#ifndef ARITHMETICINSTRUCTIONS_H
#define ARITHMETICINSTRUCTIONS_H


int iadd(Interpretador*); /*0x60*/
int ladd(Interpretador*); /*0x61*/
int fadd(Interpretador*); /*0x62*/
int dadd(Interpretador*); /*0x63*/

int isub(Interpretador*); /*0x64*/
int lsub(Interpretador*); /*0x65*/
int fsub(Interpretador*); /*0x66*/
int dsub(Interpretador*); /*0x67*/

int imul(Interpretador*); /*0x68*/
int lmul(Interpretador*); /*0x69*/
int fmul(Interpretador*); /*0x6A*/
int dmul(Interpretador*); /*0x6B*/

int idiv(Interpretador*); /*0x6C*/
int ldiv(Interpretador*); /*0x6D*/
int fdiv(Interpretador*); /*0x6E*/
int ddiv(Interpretador*); /*0x6F*/

int irem(Interpretador*); /*0x70*/
int lrem(Interpretador*); /*0x71*/
int frem(Interpretador*); /*0x72*/
int drem(Interpretador*); /*0x73*/

int ineg(Interpretador*); /*0x74*/
int lneg(Interpretador*); /*0x75*/
int fneg(Interpretador*); /*0x76*/
int dneg(Interpretador*); /*0x77*/

int ishl(Interpretador*); /*0x78*/
int ishr(Interpretador*); /*0x79*/
int iushr(Interpretador*); /*0x7A*/
int lshl(Interpretador*); /*0x7B*/
int lshr(Interpretador*); /*0x7C*/
int lushr(Interpretador*); /*0x7D*/

int iand(Interpretador*); /*0x7E*/
int land(Interpretador*); /*0x7F*/

int ior(Interpretador*); /*0x80*/
int lor(Interpretador*); /*0x81*/

int ixor(Interpretador*); /*0x82*/
int lxor(Interpretador*); /*0x83*/

int iinc(Interpretador*); /*0x84*/

int lcmp(Interpretador*); /*0x94*/
int fcmpl(Interpretador*); /*0x95*/
int fcmpg(Interpretador*); /*0x96*/
int dcmpl(Interpretador*); /*0x97*/
int dcmpg(Interpretador*); /*0x98*/

#endif
