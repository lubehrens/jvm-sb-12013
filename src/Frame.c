int emptyStack(OperandStack *top) {
	return top == NULL ;
}

void pushOperand(OperandStack **topAddress, Operand operandToPush) OperandType operand, int operandType) {
	OperandStack *p1;
	p1 = malloc(sizeof(OperandStack));
	p1->operand = operandToPush;
	p1->operand->operandType = operandToPush->operandType;
	p1->nextOperand = *topAddress;
	*topAddress = p1;
}

void stackInit(OperandStack **stackAddress) {
	*stackAddress = NULL;
}

OperandType popOperand(OperandStack **topAddress) {
	OperandStack *p1;
	OperandType operand;
	if (!emptyStack(*topAddress)) {
		operand = (*topAddress)->operand;
		p1 = *topAddress
		*topAddress = (*topAddress)->nextOperand;
		free(p1);
	} else {
		printf("A pilha esta vazia\n");
		exit(1);
	}
	return operand;
}

int emptyFrameStack(FrameStack *topFrame) {
	return topFrame == NULL ;
}

void frameStackInit(FrameStack **topFrame) {
	*topFrame = NULL;
}

void pushFrame(Frame **topFrameAddress) {
	Frame *p1;
	p1 = malloc(sizeof(Frame));
	p1->nextFrame = *topFrameAddress;
	*topFrameAddress = p1;

}

void popFrame(Frame **topFrameAddress) {
	Frame *p1;
	if (!emptyFrameStack(*topFrameAddress)) {
		p1 = *topFrameAddress;
		*topFrameAddress = (*topFrameAddress)->nextFrame;
		free(p1);
	} else {
		printf("A pilha esta vazia\n");
		exit(1);
	}
}

void frameInit(ClassList *init, ClassFile classfile, Frame *frame, char* methodName, char* descriptor) {

	ClassFile* classfile_aux;
	methodInfo* method;
	attributeInfo methodCode;
	u2 superClassIndex;
	char superClassName[100];
	int i;

	method = NULL;
	classfile_aux = &classfile;
	superClassIndex = classfile_aux->super_class;

	/* Procura o metodo pelo nome e se não encontrar, procura na super classe */
	while (classfile_aux != NULL && (method = buscaMetodoNome(*classfile_aux, methodName, descriptor)) == NULL && superClassIndex != 0) {

        superClassName = getUTF8(classfile_aux->constant_pool, classfile_aux->constant_pool[superClassIndex].info.classInfo.nameIndex));

		classfile_aux = getClassFileByName(init, superClassName);
		if (classfile_aux != NULL ) {
			superClassIndex = classfile_aux->super_class;
		}
	}

	if (method == NULL ) {
		printf("Metodo nao encontrado >> %s %s\n", methodName, descriptor);
		exit(1);
	}

	for (i = 0; i < method->attributesCount; i++) {
		if (strcmp(getUTF8(classfile_aux->constant_pool, method->attributes[i].attributeNameIndex), "Code")	== 0) {
			methodCode = method->attributes[i];
			break;
		}
	}

    /* PROBLEMA AQUI: frame->constantPool?
    * StackFrame->topoOperandStack?
    */
	StackFrame->frame->constantPool = classfile_aux->constant_pool;
	//inicializando a pilha de operandos
	stackInit(&(StackFrame->topoOperandStack));
	//Copiando a referência do código do método a ser executado.
	Frame->codigoAExecutar = methodCode.tipoInfo.code.code;
	//inicializando o array de variáveis locais
	Frame->arrayLocal = malloc(
			methodCode.tipoInfo.code.maxLocals * sizeof(OperandType));
	Frame->pc = Frame->codigoAExecutar;

}
