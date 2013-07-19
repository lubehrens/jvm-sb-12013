#ifndef LOADANDSTOREINSTRUCTIONS_H
#define LOADANDSTOREINSTRUCTIONS_H

#include "Interpretador.h"

int aconst_null(); /*0x01*/
int iconst_m1(); /*0x02*/
int iconst_0(); /*0x03*/
int iconst_1(); /*0x04*/
int iconst_2(); /*0x05*/
int iconst_3(); /*0x06*/
int iconst_4(); /*0x07*/
int iconst_5(); /*0x08*/
int lconst_0(); /*0x09*/
int lconst_1(); /*0x0A*/
int fconst_0(); /*0x0B*/
int fconst_1(); /*0x0C*/
int fconst_2(); /*0x0D*/
int dconst_0(); /*0x0E*/
int dconst_1(); /*0x0F*/
int bipush(); /*0x10*/
int sipush(); /*0x11*/
int ldc(); /*0x12*/
int ldc_w(); /*0x13*/
int ldc2_w(); /*0x14*/

int iload(); /*0x15*/
int lload(); /*0x16*/
int fload(); /*0x17*/
int dload(); /*0x18*/
int aload(); /*0x19*/
int iload_0(); /*0x1A*/
int iload_1(); /*0x1B*/
int iload_2(); /*0x1C*/
int iload_3(); /*0x1D*/
int lload_0(); /*0x1E*/
int lload_1(); /*0x1F*/
int lload_2(); /*0x20*/
int lload_3(); /*0x21*/
int fload_0(); /*0x22*/
int fload_1(); /*0x23*/
int fload_2(); /*0x24*/
int fload_3(); /*0x25*/
int dload_0(); /*0x26*/
int dload_1(); /*0x27*/
int dload_2(); /*0x28*/
int dload_3(); /*0x29*/
int aload_0(); /*0x2A*/
int aload_1(); /*0x2B*/
int aload_2(); /*0x2C*/
int aload_3(); /*0x2D*/

int istore(); /*0x36*/
int lstore(); /*0x37*/
int fstore(); /*0x38*/
int dstore(); /*0x39*/
int astore(); /*0x3A*/
int istore_0(); /*0x3B*/
int istore_1(); /*0x3C*/
int istore_2(); /*0x3D*/
int istore_3(); /*0x3E*/
int lstore_0(); /*0x3F*/
int lstore_1(); /*0x40*/
int lstore_2(); /*0x41*/
int lstore_3(); /*0x42*/
int fstore_0(); /*0x43*/
int fstore_1(); /*0x44*/
int fstore_2(); /*0x45*/
int fstore_3(); /*0x46*/
int dstore_0(); /*0x47*/
int dstore_1(); /*0x48*/
int dstore_2(); /*0x49*/
int dstore_3(); /*0x4A*/
int astore_0(); /*0x4B*/
int astore_1(); /*0x4C*/
int astore_2(); /*0x4D*/
int astore_3(); /*0x4E*/

int wide(); /*0xC4*/

#endif
