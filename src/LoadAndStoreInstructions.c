#include "LoadAndStoreInstructions.h"

/*0x01*/
int aconst_null(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.referenceType = NULL;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x02*/
int iconst_m1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = -1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x03*/
int iconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x04*/
int iconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x05*/
int iconst_2(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 2;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x06*/
int iconst_3(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 3;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x07*/
int iconst_4(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 4;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x08*/
int iconst_5(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.intType = 5;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x09*/
int lconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.longType = 0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0A*/
int lconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.longType = 1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0B*/
int fconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.floatType = 0.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0C*/
int fconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.floatType = 1.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0D*/
int fconst_2(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.floatType = 2.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0E*/
int dconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.doubleType = 0.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0F*/
int dconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.doubleType = 1.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}


