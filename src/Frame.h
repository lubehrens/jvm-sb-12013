#ifndef FRAME_H
#define FRAME_H
#define CAT1 1
#define CAT2 2

/** Estrutura que modela o array que será usado nas instruções de objetos
*/
typedef struct Array {
	int arraySize, type;
	Operand* array;
} Array;

/** Seção de ambiente de execução.
* Contém um ponteiro para a classe à qual o método pertence,
* um ponteiro para o opcode da instrução sendo lida
* e um program counter, que indica o endereço da instrução sendo lida
*/
typedef struct ExecEnvirSection {
    CpInfo *belongingClass;
    u1 *currOpcode;
    u1 *pc;
} ExecEnvirSection;

/** Estrutura de um Operando.
* Contém um inteiro que indica se é Tipo 1 ou Tipo 2 e o tipo do operando.
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
* Contém o tipo do operando, definido por uma union e um int que indica se é do Tipo 1 ou 2,
* e um ponteiro para o próximo operando da pilha.
*/
typedef struct OperandStack {
    Operand operand;
    struct OperandStack *nextOperand;
} OperandStack;

/** O Frame é composto de um array de variáveis locais, uma pilha de operandos
* e um ambiente de execução dos métodos.
*/
typedef struct Frame {
    int *localVarArray;    // array de variaveis locais de 32 bits por slot
    ExecEnvirSection execEnvir;
    OperandStack *topOperand;
} Frame;

/* ******************** Funções ******************** */

/** Função que verifica se a pilha de operandos está vazia.
* \param OperandStack* Ponteiro para a pilha de operandos
* \return 1 se a pilha estiver vazia, 0 se não estiver
*/
int emptyStack(OperandStack*);

/** Função que verifica o número de slots (32 bits) ocupados pelos primeiros argumentos.
* \param OperandStack* Ponteiro para a pilha de operandos
* \param int Número de argumentos a serem verificados
* \return int Número de slots ocupados pelos argumentos
*/
int countSlots(OperandStack* topOperand, int argNumber);

/** Função que coloca um operando na pilha de operandos.
* \param OperandStack** Endereço da pilha de operandos
* \param Operand Operando a ser empilhado
*/
void pushOperand(OperandStack**, Operand);

/** Função que inicializa a pilha de operandos.
* \param OperandStack** Endereço da pilha de operandos
*/
void stackInit(OperandStack**);

/** Função que remove um operando da pilha de operandos.
* \param OperandStack** Endereço da pilha de operandos
* \return Operando que foi desempilhado
*/
Operand popOperand(OperandStack**);

/** Função que verifica se a pilha de frames está vazia.
* \param StackFrame* Ponteiro para a pilha de frames
* \return 1 se a pilha estiver vazia, 0 se não estiver
*/
int emptyStackFrame(StackFrame*);

/** Função que inicializa a pilha de frames.
* \param Endereço da pilha de frames
*/
void frameStackInit(StackFrame**);

/** Função que cria um novo frame na pilha de frames
* \param StackFrame** Endereço da pilha de frames
*/
void pushFrame(StackFrame**);

/** Função que remove um frame da pilha de frames
* \param StackFrame** Endereço da pilha de frames
*/
void popFrame(StackFrame**);

/** Função que inicializa um frame
* \param ClassList* Lista de classes
* \param ClassFile
* \param StackFrame* Pilha de frames
* \param char* Nome do método
* \param char* Descrição do método
*/
void frameInit(ClassList*, ClassFile, StackFrame*, char*, char*);

#endif
