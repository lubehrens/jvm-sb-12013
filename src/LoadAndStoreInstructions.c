#include "LoadAndStoreInstructions.h"

/*0x01*/
int aconst_null(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.referenceType = NULL;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}
