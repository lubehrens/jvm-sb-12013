#ifndef CONTROLTRANSFERINSTRUCTIONS_H
#define CONTROLTRANSFERINSTRUCTIONS_H

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (== 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifeq(Interpretador*); /*0x99*/

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (!= 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifne(Interpretador*); /*0x9A*/

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (< 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int iflt(Interpretador*); /*0x9B*/

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (>= 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifge(Interpretador*); /*0x9C*/

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (> 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifgt(Interpretador*); /*0x9D*/

/** Retira o primeiro valor da pilha de operandos e compara com zero.
* Se a compara��o for bem sucedida (<= 0), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifle(Interpretador*); /*0x9E*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 == valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmpeq(Interpretador*); /*0x9F*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 != valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmpne(Interpretador*); /*0xA0*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 < valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmplt(Interpretador*); /*0xA1*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 >= valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmpge(Interpretador*); /*0xA2*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 > valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmpgt(Interpretador*); /*0xA3*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo int.
* Se a compara��o for bem sucedida (valor1 <= valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_icmple(Interpretador*); /*0xA4*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo referenceType.
* Se a compara��o for bem sucedida (valor1 == valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_acmpeq(Interpretador*); /*0xA5*/

/** Retira os dois primeiros valores da pilha de operandos e os compara. Ambos devem ser do tipo referenceType.
* Se a compara��o for bem sucedida (valor1 != valor2), pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int if_acmpne(Interpretador*); /*0xA6*/

/** pc = (branchbyte1 << 8) | branchbyte2
*/
int goto(Interpretador*); /*0xA7*/

/** Insere na pilha o endere�o da instru��o seguinte.
* pc = (branchbyte1 << 8) | branchbyte2
*/
int jsr(Interpretador*); /*0xA8*/

/** L� um index e usa ele para acessar uma posi��o no vetor de vari�veis locais. O valor desta posi��o deve ser do tipo returnAddress.
* pc = localVarArray[index]
*/
int ret(Interpretador*); /*0xA9*/


int tableswitch(Interpretador*); /*0xAA*/


int lookupswitch(Interpretador*); /*0xAB*/

/** Retira o primeiro valor da pilha de operandos e verifica se � NULL. O valor deve ser do tipo referenceType.
* Se a compara��o for bem sucedida, pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifnull(Interpretador*); /*0xC6*/

/** Retira o primeiro valor da pilha de operandos e verifica se n�o � NULL. O valor deve ser do tipo referenceType.
* Se a compara��o for bem sucedida, pc = (branchbyte1 << 8) | branchbyte2
* Se n�o, segue para a pr�xima instru��o
*/
int ifnonnull(Interpretador*); /*0xC7*/

/** pc = (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4
*/
int goto_w(Interpretador*); /*0xC8*/

/** Insere na pilha o endere�o da instru��o seguinte.
* pc = (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4
*/
int jsr_w(Interpretador*); /*0xC9*/

#endif
