#ifndef CONTROLTRANSFERINSTRUCTIONS_H
#define CONTROLTRANSFERINSTRUCTIONS_H

int ifeq(); /*0x99*/
int ifne(); /*0x9A*/
int iflt(); /*0x9B*/
int ifge(); /*0x9C*/
int ifgt(); /*0x9D*/
int ifle(); /*0x9E*/
int if_icmpeq(); /*0x9F*/
int if_icmpne(); /*0xA0*/
int if_icmplt(); /*0xA1*/
int if_icmpge(); /*0xA2*/
int if_icmpgt(); /*0xA3*/
int if_icmple(); /*0xA4*/
int if_acmpeq(); /*0xA5*/
int if_acmpne(); /*0xA6*/
int goto(); /*0xA7*/
int jsr(); /*0xA8*/
int ret(); /*0xA9*/
int tableswitch(); /*0xAA*/
int lookupswitch(); /*0xAB*/
int ifnull(); /*0xC6*/
int ifnonnull(); /*0xC7*/
int goto_w(); /*0xC8*/
int jsr_w(); /*0xC9*/

#endif