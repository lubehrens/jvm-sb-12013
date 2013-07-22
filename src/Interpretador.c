#include "Interpretador.h"

void initClassList(ClassList** head) {
    *head = NULL;
}

void initStaticFields(ClassList* cList, ClassFile cFile) {
    int i, j = 0;
    // Conta os campos estaticos
	for (i = 0; i < cFile.fieldsCount; i++) {
		if ((cFile.fields[i].accessFlags & ACC_STATIC) != 0) {
			cList->staticFieldsCount++;
		}
	}
	//Aloca o vetor de campos estaticos
	cList->staticFields = malloc(sizeof(Field) * cList->staticFieldsCount);
	// Insere os valores de nome e descritor no vetor e inicializa com 0
	for (i = 0; i < cFile.fieldsCount; i++) {
		if ((cFile.fields[i].accessFlags & ACC_STATIC) != 0) {
			cList->staticFields[j].name = cFile.constantPool[cFile.fields[i].nameIndex].info.UTF8Info.bytes;
			cList->staticFields[j].descriptor = cFile.constantPool[cFile.fields[i].descriptorIndex].info.UTF8Info.bytes;
			cList->staticFields[j].fieldType.longType = 0;
			j++;
		}
	}
}

void appendClassList(ClassList** head, ClassFile classFile) {
    ClassList* cList, cListAux;

    // Inicializa valores do novo elemento
    cList = malloc(sizeof(ClassList));
    cList->classFile = classFile;
    cList->staticFieldsCount = 0;
    cList->staticFields = NULL;
    cList->objectsList = NULL;

    // Inicializa os campos estaticos
    initStaticFields(cList, classFile);

    // Atualiza ponteiro para proximo elemento
    if (*head == NULL) {
        *head = cList;
    } else {
        cListAux = *head;
        while(cListAux->nextClass != NULL)
            cListAux = cListAux->nextClass;
        cListAux->nextClass = cList;
    }
    cList->nextClass = NULL;
}

ClassFile* loadClass(Interpretador* interpretador, char* className) {
    ClassFile* cFile = getClassFileByName(className);
    if (cFile == NULL) {
        cFile = readClass(className);
        appendClassList(&(interpretador->initClass), cFile);
        // Inicia <clinit>
        if (getMethod(*cFile, "<clinit>", "()V") != NULL) {
            methodInit(className, "<clinit>", "()V", interpretador, 0);
            methodExec(interpretador);
        }
    }
}

/*
void mainInit(char* className, Interpretador* interpretador, int paramsNumber, char** cmdLineParams) {
    char* methodName = "main", methodDescriptor = "([Ljava/lang/String;)V";
    ClassFile* cFile = loadClass(interpretador, className);
    pushFrame(&(interpretador->topStackFrame));
    frameInit(interpretador->initClass, *cFile, interpretador->topStackFrame, methodName, methodDescriptor);

}
*/
void methodInit(char* className, char* methodName, char* methodDescriptor, Interpretador* interpretador,int paramsNumber) {
    ClassFile* cFile = loadClass(interpretador, className);

    pushFrame(&(interpretador->topStackFrame));
    frameInit(interpretador->initClass, *cFile, interpretador->topStackFrame, methodName, methodDescriptor);
    for (i = countSlots(interpretador->topStackFrame->nextFrame.frame->topOperand) - 1; i >= 0; i--) {
        if (interpretador->topStackFrame->nextFrame.frame->topOperand.operand.type32_64 == CAT2)
            i--;
        interpretador->topStackFrame.frame->localVarArray[i] = &(interpretador->topStackFrame->nextFrame.frame->topOperand);
    }
}
void methodExec(Interpretador* interpretador) {
    int ret_ = 0;
	u1 opcode;
	while (!ret_) {
		opcode = *(interpretador->topStackFrame->frame->execEnvir->pc);
        interpretador->topStackFrame->frame->execEnvir->pc++;
		ret_ = InstructionArray[opcode](interpretador);
	}
}
