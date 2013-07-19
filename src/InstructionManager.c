#include "InstructionManager.h"

int (*InstructionArray[])(Interpretador *interpretador) = {
	nop, // 0x00
    aconst_null,// 0x1
    iconst_m1,// 0x2
    iconst_0,// 0x3
    iconst_1,// 0x4
    iconst_2,// 0x5
    iconst_3,// 0x6
    iconst_4,// 0x7
    iconst_5,// 0x8
    lconst_0,// 0x9
    lconst_1,// 0xA
    fconst_0,// 0xB
    fconst_1,// 0xC
    fconst_2,// 0xD
    dconst_0,// 0xE
    dconst_1,// 0xF
    bipush,// 0x10
    sipush,// 0x11
    ldc,// 0x12
    ldc_w,// 0x13
    ldc2_w,// 0x14
    iload,// 0x15
    lload,// 0x16
    fload,// 0x17
    dload,// 0x18
    aload,// 0x19
    iload_0,// 0x1A
    iload_1,// 0x1B
    iload_2,// 0x1C
    iload_3,// 0x1D
    lload_0,// 0x1E
    lload_1,// 0x1F
    lload_2,// 0x20
    lload_3,// 0x21
    fload_0,// 0x22
    fload_1,// 0x23
    fload_2,// 0x24
    fload_3,// 0x25
    dload_0,// 0x26
    dload_1,// 0x27
    dload_2,// 0x28
    dload_3,// 0x29
    aload_0,// 0x2A
    aload_1,// 0x2B
    aload_2,// 0x2C
    aload_3,// 0x2D
    iaload,// 0x2E
    laload,// 0x2F
    faload,// 0x30
    daload,// 0x31
    aaload,// 0x32
    iaload,// 0x33
    iaload,// 0x34
    iaload,// 0x35
    store,// 0x36
    store,// 0x37
    store,// 0x38
    store,// 0x39
    store,// 0x3A
    store_0,// 0x3B
    store_1,// 0x3C
    store_2,// 0x3D
    store_3,// 0x3E
    store_0,// 0x3F
    store_1,// 0x40
    store_2,// 0x41
    store_3,// 0x42
    store_0,// 0x43
    store_1,// 0x44
    store_2,// 0x45
    store_3,// 0x46
    store_0,// 0x47
    store_1,// 0x48
    store_2,// 0x49
    store_3,// 0x4A
    store_0,// 0x4B
    store_1,// 0x4C
    store_2,// 0x4D
    store_3,// 0x4E
    iastore,// 0x4F
    lastore,// 0x50
    fastore,// 0x51
    dastore,// 0x52
    aastore,// 0x53
    iastore,// 0x54
    iastore,// 0x55
    iastore,// 0x56
    pop,// 0x57
    pop2,// 0x58
    dup,//0x59
    dup_x1,//0x5A
    dup_x2,//0x5B
    dup2,// 0x5C
    dup2_x1,// 0x5D
    dup2_x2,// 0x5E
    swap,// 0x5F
    iadd,// 0x60
    ladd,// 0x61
    fadd,// 0x62
    dadd,// 0x63
    isub,// 0x64
    lsub,// 0x65
    fsub,// 0x66
    dsub,// 0x67
    imul,// 0x68
    lmul,// 0x69
    fmul,// 0x6A
    dmul,// 0x6B
    idiv,// 0x6C
    ldiv,// 0x6D
    fdiv,// 0x6E
    ddiv,// 0x6F
    irem,// 0x70
    lrem,// 0x71
    frem,// 0x72
    drem,// 0x73
    ineg,// 0x74
    lneg,// 0x75
    fneg,// 0x76
    dneg,// 0x77
    ishl,// 0x78
    lshl,// 0x79
    ishr,// 0x7A
    lshr,// 0x7B
    iushr,// 0x7C
    lushr,// 0x7D
    iand,// 0x7E
    land,// 0x7F
    ior,// 0x80
    lor,// 0x81
    ixor,// 0x82
    lxor,// 0x83
    iinc,// 0x84
    i2l,// 0x85
    i2f,// 0x86
    i2d,// 0x87
    l2i,// 0x88
    l2f,// 0x89
    l2d,// 0x8A
    f2i,// 0x8B
    f2l,// 0x8C
    f2d,// 0x8D
    d2i,// 0x8E
    d2l,// 0x8F
    d2f,// 0x90
    i2c,// 0x91
    i2c,// 0x92
    i2s,// 0x93
    lcmp,// 0x94
    fcmpl,// 0x95
    fcmpg,// 0x96
    dcmpl,// 0x97
    dcmpg,// 0x98
    ifeq,// 0x99
    ifne,// 0x9A
    iflt,// 0x9B
    ifge,// 0x9C
    ifgt,// 0x9D
    ifle,// 0x9E
    if_icmpeq,// 0x9F
    if_icmpne,// 0xA0
    if_icmplt,// 0xA1
    if_icmpge,// 0xA2
    if_icmpgt,// 0xA3
    if_icmple,// 0xA4
    if_acmpeq,// 0XA5
    if_acmpne,// 0xA6
    goto_,// 0xA7
    jsr,// 0xA8
    ret,// 0xA9
    tableswitch,// 0xAA
    lookupswitch,// 0xAB
    ireturn,// 0xAC
    lreturn,// 0xAD
    freturn,// 0xAE
    dreturn,// 0xAF
    areturn,// 0xB0
    return_,// 0xB1
    getstatic,// 0xB2
    putstatic,// 0xB3
    getfield,// 0xB4
    putfield,// 0xB5
    invokevirtual,// 0xB6
    invokespecial,// 0xB7
    invokestatic,// 0xB8
    nop,//nop,// 0xB9
    nop,//nop,// 0xBA
    new,// 0xBB
    newarray,// 0xBC
    anewarray,// 0xBD
    arraylength,// 0xBE
    nop,//athrow,// 0xBF
    nop,//checkcast,// 0xC0
    nop,//instanceof,// 0xC1
    nop,//nop,// 0xC2
    nop,//nop,// 0xC3
    nop,//wide,// 0xC4
    multianewarray,// 0xC5
    ifnull,// 0xC6
    ifnonnull,// 0xC7
    goto_w,// 0xC8
    jsr_w// 0xC9
};
