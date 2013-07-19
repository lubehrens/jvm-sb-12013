int emptyStack(OperandStack *top) {
	return top == NULL ;
}

void pushOperando(OperandStack **topAddress, OperandType operand, int operandType) {
	OperandStack *p1;
	p1 = malloc(sizeof(OperandStack));
	p1->operand = operandoPassado;
	p1->operandType = operandoType;
	p1->nextOperand = *topAddress;
	*topAddress = p1;
}

void initializeStack(OperandStack **stackAddress) {
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

void initializeFrameStack(FrameStack **topFrame) {
	*topFrame = NULL;
}

/*
 * Fun��o que coloca uma frame nova na pilha.
 *
 * !! ATEN��O !! - Inicializar a frame ap�s dar o push.
 */
void pushFrame(frame **endFrameAtual) {

	frame *p1;

	p1 = malloc(sizeof(frame));

	p1->frameAbaixo = *endFrameAtual;
	*endFrameAtual = p1;

}

/*
 * Fun��o que retira uma frame da pilha de frames
 */
void popFrame(frame **endFrameAtual) {

	frame *p1;

	if (!pilhaFramesVazia(*endFrameAtual)) {
		p1 = *endFrameAtual;
		*endFrameAtual = (*endFrameAtual)->frameAbaixo;
		free(p1);
	} else {
		printf("ERRO em popFrame : pilha vazia\n");
		exit(1);
	}

}

/*
 * Fun��o que inicializa uma frame, com o c�digo correto a ser executado
 *
 * Caso o m�todo que quer ser executado n�o possa ser achado na classe atual, procuramos nas super classes.
 */
void inicializaFrame(listaClasses *inicioLista, ClassFile cf, frame *frame,
		char* nomeMetodo, char* descriptor) {

	ClassFile* cfAux;
	methodInfo* metodo;
	attributeInfo codigoMetodo;
	u2 indiceSuperClasse;
	char nomeSuperClasse[100];
	int i;

	metodo = NULL;
	cfAux = &cf;
	indiceSuperClasse = cfAux->super_class;

	// Achar o m�todo pelo nome
	// Se n�o acharmos, passamos para a super classe para ver se est� l�
	while (cfAux != NULL
			&& (metodo = buscaMetodoNome(*cfAux, nomeMetodo, descriptor))
					== NULL && indiceSuperClasse != 0) {

		strcpy(nomeSuperClasse,
				buscaUTF8ConstPool(cfAux->constant_pool,
						cfAux->constant_pool[indiceSuperClasse].info.classInfo.nameIndex));

		cfAux = buscaClassFileNome(inicioLista, nomeSuperClasse);
		if (cfAux != NULL ) {
			indiceSuperClasse = cfAux->super_class;
		}
	}

	// N�o conseguimos achar o m�todo :(
	if (metodo == NULL ) {
		printf("ERRO: NoSuchMethodError - %s %s\n", nomeMetodo, descriptor);
		exit(1);
	}

	//achar o atributo Code , percorre a lista de atributos buscando o atributo Code
	for (i = 0; i < metodo->attributesCount; i++) {
		if (strcmp(
				buscaUTF8ConstPool(cfAux->constant_pool,
						metodo->attributes[i].attributeNameIndex), "Code")
				== 0) {
			codigoMetodo = metodo->attributes[i];
			break;
		}
	}

	frame->constantPool = cfAux->constant_pool;
	//inicializando a pilha de operandos
	inicializaPilha(&(frame->topoOperandStack));
	//Copiando a refer�ncia do c�digo do m�todo a ser executado.
	frame->codigoAExecutar = codigoMetodo.tipoInfo.code.code;
	//inicializando o array de vari�veis locais
	frame->arrayLocal = malloc(
			codigoMetodo.tipoInfo.code.maxLocals * sizeof(OperandType));
	frame->pc = frame->codigoAExecutar;

}
