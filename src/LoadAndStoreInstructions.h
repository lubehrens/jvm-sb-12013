#ifndef LOADANDSTOREINSTRUCTIONS_H
#define LOADANDSTOREINSTRUCTIONS_H

#include "Interpretador.h"
#include "Frame.h"
#include "InstructionManager.h"

/** Chamada para substituir instruções não implementadas */
int nop(Interpretador*);
/** Insere na pilha de operandos do frame corrente uma referência nula */
int aconst_null(Interpretador*); /*0x01*/
/** Insere na pilha de operandos do frame corrente a constante int -1 */
int iconst_m1(Interpretador*); /*0x02*/
/** Insere na pilha de operandos do frame corrente a constante int 0 */
int iconst_0(Interpretador*); /*0x03*/
/** Insere na pilha de operandos do frame corrente a constante int 1 */
int iconst_1(Interpretador*); /*0x04*/
/** Insere na pilha de operandos do frame corrente a constante int 2 */
int iconst_2(Interpretador*); /*0x05*/
/** Insere na pilha de operandos do frame corrente a constante int 3 */
int iconst_3(Interpretador*); /*0x06*/
/** Insere na pilha de operandos do frame corrente a constante int 4 */
int iconst_4(Interpretador*); /*0x07*/
/** Insere na pilha de operandos do frame corrente a constante int 5 */
int iconst_5(Interpretador*); /*0x08*/
/** Insere na pilha de operandos do frame corrente a constante long 0 */
int lconst_0(Interpretador*); /*0x09*/
/** Insere na pilha de operandos do frame corrente a constante long 1 */
int lconst_1(Interpretador*); /*0x0A*/
/** Insere na pilha de operandos do frame corrente a constante float 0.0 */
int fconst_0(Interpretador*); /*0x0B*/
/** Insere na pilha de operandos do frame corrente a constante float 1.0 */
int fconst_1(Interpretador*); /*0x0C*/
/** Insere na pilha de operandos do frame corrente a constante float 2.0 */
int fconst_2(Interpretador*); /*0x0D*/
/** Insere na pilha de operandos do frame corrente a constante double 0.0 */
int dconst_0(Interpretador*); /*0x0E*/
/** Insere na pilha de operandos do frame corrente a constante double 1.0 */
int dconst_1(Interpretador*); /*0x0F*/
/** Insere na pilha de operandos do frame corrente o valor apontado pelo índice
*   representado pelo byte que segue logo após o opcode
*/
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
