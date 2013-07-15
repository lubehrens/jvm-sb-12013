#ifndef ARITHMETICINSTRUCTIONS_H
#define ARITHMETICINSTRUCTIONS_H


int iadd(); /*0x60*/
int ladd(); /*0x61*/
int fadd(); /*0x62*/
int dadd(); /*0x63*/

int isub(); /*0x64*/
int lsub(); /*0x65*/
int fsub(); /*0x66*/
int dsub(); /*0x67*/

int imul(); /*0x68*/
int lmul(); /*0x69*/
int fmul(); /*0x6A*/
int dmul(); /*0x6B*/

int idiv(); /*0x6C*/
int ldiv(); /*0x6D*/
int fdiv(); /*0x6E*/
int ddiv(); /*0x6F*/

int irem(); /*0x70*/
int lrem(); /*0x71*/
int frem(); /*0x72*/
int drem(); /*0x73*/

int ineg(); /*0x74*/
int lneg(); /*0x75*/
int fneg(); /*0x76*/
int dneg(); /*0x77*/

int ishl(); /*0x78*/
int ishr(); /*0x79*/
int iushr(); /*0x7A*/
int lshl(); /*0x7B*/
int lshr(); /*0x7C*/
int lushr(); /*0x7D*/

int iand(); /*0x7E*/
int land(); /*0x7F*/

int ior(); /*0x80*/
int lor(); /*0x81*/

int ixor(); /*0x82*/
int lxor(); /*0x83*/

int iinc(); /*0x84*/

int lcmp(); /*0x94*/
int fcmpl(); /*0x95*/
int fcmpg(); /*0x96*/
int dcmpl(); /*0x97*/
int dcmpg(); /*0x98*/

#endif