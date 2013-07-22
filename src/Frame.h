#ifndef FRAME_H
#define FRAME_H
#define CAT1 1
#define CAT2 2

/** Estrutura que modela o array que ser� usado nas instru��es de objetos
*/
typedef struct Array {
	int arraySize, type;
	Operand* array;
} Array;

/** Se��o de ambiente de execu��o.
* Cont�m um ponteiro para a classe � qual o m�todo pertence,
* um ponteiro para o opcode da instru��o sendo lida
* e um program counter, que indica o endere�o da instru��o sendo lida
*/
typedef struct ExecEnvirSection {
    CpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
} ExecEnvirSection;

/** Estrutura de um Operando.
* Cont�m um inteiro que indica se � Tipo 1 ou Tipo 2 e o tipo do operando.
*/
typedef struct Operand {
    int type32_64; /*1: operandos do tipo 1 | 2: operandos do tipo 2*/
    union OperandType {
        int intType;
        long long longType;
        float floatType;
        double doubleType;
        void* referenceType;
        char byteType;
        u1 charType;
        short shortType;
    } operandType;
} Operand;

/** Pilha de operandos.
* Cont�m o tipo do operando, definido por uma union e um int que indica se � do Tipo 1 ou 2,
* e um ponteiro para o pr�ximo operando da pilha.
*/
typedef struct OperandStack {
    Operand operand;
    struct OperandStack *nextOperand;
} OperandStack;

/** O Frame � composto de um array de vari�veis locais, uma pilha de operandos
* e um ambiente de execu��o dos m�todos.
*/
typedef struct Frame {
    int *localVarArray;    // array de variaveis locais de 32 bits por slot
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame;

/* ******************** Fun��es ******************** */

/** Fun��o que verifica se a pilha de operandos est� vazia.
* \param OperandStack* Ponteiro para a pilha de operandos
* \return 1 se a pilha estiver vazia, 0 se n�o estiver
*/
int emptyStack(OperandStack*);

/** Fun��o que verifica o n�mero de slots (32 bits) ocupados pelos primeiros argumentos.
* \param OperandStack* Ponteiro para a pilha de operandos
* \param int N�mero de argumentos a serem verificados
* \return int N�mero de slots ocupados pelos argumentos
*/
int countSlots(OperandStack* topOperand, int argNumber);

/** Fun��o que coloca um operando na pilha de operandos.
* \param OperandStack** Endere�o da pilha de operandos
* \param Operand Operando a ser empilhado
*/
void pushOperand(OperandStack**, Operand);

/** Fun��o que inicializa a pilha de operandos.
* \param OperandStack** Endere�o da pilha de operandos
*/
void stackInit(OperandStack**);

/** Fun��o que remove um operando da pilha de operandos.
* \param OperandStack** Endere�o da pilha de operandos
* \return Operando que foi desempilhado
*/
Operand popOperand(OperandStack**);

/** Fun��o que verifica se a pilha de frames est� vazia.
* \param StackFrame* Ponteiro para a pilha de frames
* \return 1 se a pilha estiver vazia, 0 se n�o estiver
*/
int emptyStackFrame(StackFrame*);

/** Fun��o que inicializa a pilha de frames.
* \param Endere�o da pilha de frames
*/
void frameStackInit(StackFrame**);

/** Fun��o que cria um novo frame na pilha de frames
* \param StackFrame** Endere�o da pilha de frames
*/
void pushFrame(StackFrame**);

/** Fun��o que remove um frame da pilha de frames
* \param StackFrame** Endere�o da pilha de frames
*/
void popFrame(StackFrame**);

/** Fun��o que inicializa um frame
* \param ClassList* Lista de classes
* \param ClassFile
* \param StackFrame* Pilha de frames
* \param char* Nome do m�todo
* \param char* Descri��o do m�todo
*/
void frameInit(ClassList*, ClassFile, StackFrame*, char*, char*);

#endif
