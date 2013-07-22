#include "MethodInvocationInstructions.h"

/*0xB6*/
int invokevirtual(Interpretador* interpretador) {
}

/*0xB7*/
int invokespecial(Interpretador* interpretador) {
    int byte1, byte2, argNumber;
    u2 methodIndex, classIndex, classNameIndex, nameAndTypeIndex, methodNameIndex, methodDescriptorIndex;
    char *methodName, *className, *methodDescriptor;
    // Pega os bytes do index logo apos o opcode da instrucao
    byte1 = *(interpretador->topStackFrame->frame->execEnvir->pc);
    interpretador->topStackFrame->frame->execEnvir->pc++;
    byte2 = *(interpretador->topStackFrame->frame->execEnvir->pc);
    interpretador->topStackFrame->frame->execEnvir->pc++;
    // Constroi o index do metodo
    methodIndex = (byte1 << 8) | byte2;
    // Pega os indices das informacoes do metodo no constant pool
    classIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[methodIndex].info.MethodrefInfo.classIndex;
    classNameIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[classIndex].info.classInfo.nameIndex;
    nameAndTypeIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[methodIndex].info.MethodrefInfo.nameAndTypeIndex;
    methodNameIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[nameAndTypeIndex].info.NameAndTypeInfo.nameIndex;
    methodDescriptorIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[nameAndTypeIndex].info.NameAndTypeInfo.descriptorIndex;
    // Pega as informacoes a partir dos indices
    methodName = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[methodNameIndex].info.UTF8Info.bytes;
    methodDescriptor = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[methodDescriptorIndex].info.UTF8Info.bytes;
    className = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[classNameIndex].info.UTF8Info.bytes;
    // Pega o numero de argumentos
    argNumber = methodArgsCount(methodDescriptor);
    // Executa o m�todo
    methodInit(className, methodName, methodDescriptor, argNumber + 1);
    methodExec(interpretador);
    return 0;
}

/*0xB8*/
int invokestatic(Interpretador* interpretador) {
    int byte1, byte2, argNumber;
    u2 methodIndex, classIndex, classNameIndex, nameAndTypeIndex, methodNameIndex, methodDescriptorIndex;
    char *methodName, *className, *methodDescriptor;
    // Pega os bytes do index logo apos o opcode da instrucao
    byte1 = *(interpretador->topStackFrame->frame->execEnvir->pc);
    interpretador->topStackFrame->frame->execEnvir->pc++;
    byte2 = *(interpretador->topStackFrame->frame->execEnvir->pc);
    interpretador->topStackFrame->frame->execEnvir->pc++;
    // Constroi o index do metodo
    methodIndex = (byte1 << 8) | byte2;
    // Pega os indices das informacoes do metodo no constant pool
    classIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[methodIndex].info.MethodrefInfo.classIndex;
    classNameIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[classIndex].info.classInfo.nameIndex;
    nameAndTypeIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[methodIndex].info.MethodrefInfo.nameAndTypeIndex;
    methodNameIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[nameAndTypeIndex].info.NameAndTypeInfo.nameIndex;
    methodDescriptorIndex = interpretador->topStackFrame->frame->execEnvir->belongingClass[nameAndTypeIndex].info.NameAndTypeInfo.descriptorIndex;
    // Pega as informacoes a partir dos indices
    methodName = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[methodNameIndex].info.UTF8Info.bytes;
    methodDescriptor = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[methodDescriptorIndex].info.UTF8Info.bytes;
    className = (char*) interpretador->topStackFrame->frame->execEnvir->belongingClass[classNameIndex].info.UTF8Info.bytes;
    // Pega o numero de argumentos
    argNumber = methodArgsCount(methodDescriptor);
    // Executa se nao apresenta o m�todo nativo registerNatives
    if (strcmp(nomeClasse, "java/lang/Object") != 0 || strcmp(nomeMetodo, "registerNatives") != 0 || strcmp(descritor, "()V") != 0) {
		// Carrega a classe em memoria se nao estiver carregada
		loadClass(interpretador, className);
		methodInit(className, methodName, methodDescriptor, argNumber + 1);
        methodExec(interpretador);
	}
	return 0;
}

/*0xB9*/
int invokeinterface(Interpretador* interpretador) {
}

#endif
