#include "LoadAndStoreInstructions.h"

int nop(Interpretador*) {
    return 0;
}

/*0x01*/
int aconst_null(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.referenceType = NULL;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x02*/
int iconst_m1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = -1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x03*/
int iconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x04*/
int iconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x05*/
int iconst_2(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 2;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x06*/
int iconst_3(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 3;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x07*/
int iconst_4(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 4;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x08*/
int iconst_5(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = 5;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x09*/
int lconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.operandType.longType = 0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0A*/
int lconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.operandType.longType = 1;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0B*/
int fconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.floatType = 0.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0C*/
int fconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.floatType = 1.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0D*/
int fconst_2(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.floatType = 2.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0E*/
int dconst_0(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.operandType.doubleType = 0.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x0F*/
int dconst_1(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    operand.operandType.doubleType = 1.0;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x10*/
int bipush(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    operand.operandType.intType = (int) interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x11*/
int sipush(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    u1 byte1, byte2;
    byte1 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    byte2 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    operand.operandType.intType = (byte1 << 8) | byte2;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x12*/
int ldc(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    u1 index = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    switch (interpretador->topStackFrame->frame->execEnvir->belongingClass[index].tag) {
        case CONSTANT_Integer:
            operand.operandType.intType = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.IntegerInfo.bytes;
            break;
        case CONSTANT_Float:
            operand.operandType.floatType = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.FloatInfo.bytes;
            break;
        case CONSTANT_String:
            u2 stringIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.StringInfo.stringIndex;
            operand.operandType.referenceType = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[stringIndex].info.Utf8Info.bytes;
            break;
        default:
            printf("Indice invalido.\n");
            exit(1);
	}
	pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x13*/
int ldc_w(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    u1 byte1, byte2;
    u2 index;
    byte1 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    byte2 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    index = (byte1 << 8) | byte2;
    switch (interpretador->topStackFrame->frame->execEnvir->belongingClass[index].tag) {
        case CONSTANT_Integer:
            operand.operandType.intType = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.IntegerInfo.bytes;
            break;
        case CONSTANT_Float:
            operand.operandType.floatType = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.FloatInfo.bytes;
            break;
        case CONSTANT_String:
            u2 stringIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.StringInfo.stringIndex;
            operand.operandType.referenceType = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[stringIndex].info.Utf8Info.bytes;
            break;
        default:
            printf("Indice invalido.\n");
            exit(1);
	}
	pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x14*/
int ldc2_w(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT2;
    u1 byte1, byte2;
    u2 index;
    u4 hi, lo;
    byte1 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    byte2 = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    index = (byte1 << 8) | byte2;
    switch (interpretador->topStackFrame->frame->execEnvir->belongingClass[index].tag) {
        case CONSTANT_Double:
            hi = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.DoubleInfo.highBytes;
            lo = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.DoubleInfo.lowBytes;
            operand.operandType.doubleType = (double)((long long) hi << 32 | lo);
            break;
        case CONSTANT_Long:
            hi = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.LongInfo.highBytes;
            lo = interpretador->topStackFrame->frame->execEnvir->belongingClass[index].info.LongInfo.lowBytes;
            operand.operandType.longType = (long long) hi << 32 | lo;
            break;
        default:
            printf("Indice invalido.\n");
            exit(1);
    }
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x15*/
int iload(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT1;
    u1 index = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    operand.operandType.intType = interpretador->topStackFrame->frame->localVarArray[index];
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x16*/
int lload(Interpretador* interpretador) {
    Operand operand;
    operand.type32_64 = CAT2;
    u1 index = interpretador->topStackFrame->frame->execEnvir->pc;
    u4 hi, lo;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    hi = interpretador->topStackFrame->frame->localVarArray[index];
    lo = interpretador->topStackFrame->frame->localVarArray[index+1];
    operand.operandType.longType = (long long) hi << 32 | lo;
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x17*/
int fload(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT1;
    u1 index = interpretador->topStackFrame->frame->execEnvir->pc;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    operand.operandType.floatType = (float) interpretador->topStackFrame->frame->localVarArray[index];
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}

/*0x18*/
int dload(Interpretador*) {
    Operand operand;
    operand.type32_64 = CAT2;
    u1 index = interpretador->topStackFrame->frame->execEnvir->pc;
    u4 hi, lo;
    interpretador->topStackFrame->frame->execEnvir->pc++;
    hi = interpretador->topStackFrame->frame->localVarArray[index];
    lo = interpretador->topStackFrame->frame->localVarArray[index+1];
    operand.operandType.doubleType = (double) ((long long) hi << 32 | lo);
    pushOperand(&(interpretador->topStackFrame->frame->topOperand), operand);
    return 0;
}




