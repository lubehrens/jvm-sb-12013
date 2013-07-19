#ifndef CONTROLTRANSFERINSTRUCTIONS_H
#define CONTROLTRANSFERINSTRUCTIONS_H

int ifeq(Interpretador*); /*0x99*/
int ifne(Interpretador*); /*0x9A*/
int iflt(Interpretador*); /*0x9B*/
int ifge(Interpretador*); /*0x9C*/
int ifgt(Interpretador*); /*0x9D*/
int ifle(Interpretador*); /*0x9E*/
int if_icmpeq(Interpretador*); /*0x9F*/
int if_icmpne(Interpretador*); /*0xA0*/
int if_icmplt(Interpretador*); /*0xA1*/
int if_icmpge(Interpretador*); /*0xA2*/
int if_icmpgt(Interpretador*); /*0xA3*/
int if_icmple(Interpretador*); /*0xA4*/
int if_acmpeq(Interpretador*); /*0xA5*/
int if_acmpne(Interpretador*); /*0xA6*/
int goto(Interpretador*); /*0xA7*/
int jsr(Interpretador*); /*0xA8*/
int ret(Interpretador*); /*0xA9*/
int tableswitch(Interpretador*); /*0xAA*/
int lookupswitch(Interpretador*); /*0xAB*/
int ifnull(Interpretador*); /*0xC6*/
int ifnonnull(Interpretador*); /*0xC7*/
int goto_w(Interpretador*); /*0xC8*/
int jsr_w(Interpretador*); /*0xC9*/

#endif
