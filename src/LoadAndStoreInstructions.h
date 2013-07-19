#ifndef LOADANDSTOREINSTRUCTIONS_H
#define LOADANDSTOREINSTRUCTIONS_H

#include "Interpretador.h"

int aconst_null(Interpretador*); /*0x01*/
int iconst_m1(Interpretador*); /*0x02*/
int iconst_0(Interpretador*); /*0x03*/
int iconst_1(Interpretador*); /*0x04*/
int iconst_2(Interpretador*); /*0x05*/
int iconst_3(Interpretador*); /*0x06*/
int iconst_4(Interpretador*); /*0x07*/
int iconst_5(Interpretador*); /*0x08*/
int lconst_0(Interpretador*); /*0x09*/
int lconst_1(Interpretador*); /*0x0A*/
int fconst_0(Interpretador*); /*0x0B*/
int fconst_1(Interpretador*); /*0x0C*/
int fconst_2(Interpretador*); /*0x0D*/
int dconst_0(Interpretador*); /*0x0E*/
int dconst_1(Interpretador*); /*0x0F*/
int bipush(Interpretador*); /*0x10*/
int sipush(Interpretador*); /*0x11*/
int ldc(Interpretador*); /*0x12*/
int ldc_w(Interpretador*); /*0x13*/
int ldc2_w(Interpretador*); /*0x14*/

int iload(Interpretador*); /*0x15*/
int lload(Interpretador*); /*0x16*/
int fload(Interpretador*); /*0x17*/
int dload(Interpretador*); /*0x18*/
int aload(Interpretador*); /*0x19*/
int iload_0(Interpretador*); /*0x1A*/
int iload_1(Interpretador*); /*0x1B*/
int iload_2(Interpretador*); /*0x1C*/
int iload_3(Interpretador*); /*0x1D*/
int lload_0(Interpretador*); /*0x1E*/
int lload_1(Interpretador*); /*0x1F*/
int lload_2(Interpretador*); /*0x20*/
int lload_3(Interpretador*); /*0x21*/
int fload_0(Interpretador*); /*0x22*/
int fload_1(Interpretador*); /*0x23*/
int fload_2(Interpretador*); /*0x24*/
int fload_3(Interpretador*); /*0x25*/
int dload_0(Interpretador*); /*0x26*/
int dload_1(Interpretador*); /*0x27*/
int dload_2(Interpretador*); /*0x28*/
int dload_3(Interpretador*); /*0x29*/
int aload_0(Interpretador*); /*0x2A*/
int aload_1(Interpretador*); /*0x2B*/
int aload_2(Interpretador*); /*0x2C*/
int aload_3(Interpretador*); /*0x2D*/

int istore(Interpretador*); /*0x36*/
int lstore(Interpretador*); /*0x37*/
int fstore(Interpretador*); /*0x38*/
int dstore(Interpretador*); /*0x39*/
int astore(Interpretador*); /*0x3A*/
int istore_0(Interpretador*); /*0x3B*/
int istore_1(Interpretador*); /*0x3C*/
int istore_2(Interpretador*); /*0x3D*/
int istore_3(Interpretador*); /*0x3E*/
int lstore_0(Interpretador*); /*0x3F*/
int lstore_1(Interpretador*); /*0x40*/
int lstore_2(Interpretador*); /*0x41*/
int lstore_3(Interpretador*); /*0x42*/
int fstore_0(Interpretador*); /*0x43*/
int fstore_1(Interpretador*); /*0x44*/
int fstore_2(Interpretador*); /*0x45*/
int fstore_3(Interpretador*); /*0x46*/
int dstore_0(Interpretador*); /*0x47*/
int dstore_1(Interpretador*); /*0x48*/
int dstore_2(Interpretador*); /*0x49*/
int dstore_3(Interpretador*); /*0x4A*/
int astore_0(Interpretador*); /*0x4B*/
int astore_1(Interpretador*); /*0x4C*/
int astore_2(Interpretador*); /*0x4D*/
int astore_3(Interpretador*); /*0x4E*/

int wide(Interpretador*); /*0xC4*/

#endif
