int emptyStack(OperandStack *top) {
	return top == NULL ;
}

void pushOperand(OperandStack **topAddress, Operand operandToPush) {
	OperandStack *p1;
	p1 = malloc(sizeof(OperandStack));
	p1->operand = operandToPush;
	p1->nextOperand = *topAddress;
	*topAddress = p1;
}

void stackInit(OperandStack **stackAddress) {
	*stackAddress = NULL;
}

Operand popOperand(OperandStack **topAddress) {
	OperandStack *p1;
	Operand operand;
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

int emptyStackFrame(StackFrame *topFrame) {
	return topFrame == NULL ;
}

void frameStackInit(StackFrame **topFrame) {
	*topFrame = NULL;
}

void pushFrame(StackFrame **topFrameAddress) {
	Frame *p1;
	p1 = malloc(sizeof(StackFrame));
	p1->nextFrame = *topFrameAddress;
	*topFrameAddress = p1;
}

void popFrame(StackFrame **topFrameAddress) {
	Frame *p1;
	if (!emptyStackFrame(*topFrameAddress)) {
		p1 = *topFrameAddress;
		*topFrameAddress = (*topFrameAddress)->nextFrame;
		free(p1);
	} else {
		printf("A pilha esta vazia\n");
		exit(1);
	}
}

void frameInit(ClassList *init, ClassFile classfile, StackFrame *stackFrame, char* methodName, char* descriptor) {

	ClassFile* classfile_aux;
	MethodInfo* method;
	AttributeInfo methodCode;
	u2 superClassIndex;
	char superClassName[100];
	int i;

	method = NULL;
	classfile_aux = &classfile;
	superClassIndex = classfile_aux->super_class;

	/* Procura o metodo pelo nome e se não encontrar, procura na super classe */
	while (classfile_aux != NULL && (method = getMethodByName(*classfile_aux, methodName, descriptor)) == NULL && superClassIndex != 0) {

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

    /* belongingClass do frame recebe o constant_pool do classFile */
	stackFrame->frame->execEnvir->belongingClass = classfile_aux->constant_pool;
	/* inicializa a pilha de operandos */
	stackInit(&(stackFrame->frame->topOperand));
	/* seta o opcode do método que vai ser executado */
	stackFrame->frame->execEnvir->currOpcode = methodCode.tipoInfo.code.code;
	/* inicializa vetor de variáveis locais */
	stackFrame->localVarArray = malloc(methodCode.tipoInfo.code.maxLocals * sizeof(int));
	/* seta o pc */
	stackFrame->execEnvir->pc = stackFrame->frame->execEnvir->currOpcode;
}
