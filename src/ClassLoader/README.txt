CLassLoader criado a parte para verificar se está fazendo a leitura correta.


*** COMO EXECUTAR: ***

nome_programa.exe opcao_imprimir arquivo.Class

OBS: opcao_imprimir pode ser
		0: para não imprimir o classfile
		1: para imprimir o classfile


*** EXEMPLO DE COMPILAÇÃO E EXECUÇÃO ***

gcc -ansi -Wall -std=c99 -c main.c ClassLoader.c AuxiliarFunctions.c
gcc main.o ClassLoader.o AuxiliarFunctions.o -o classLoader
classLoader.exe 1 Carta.class


*** O QUE FALTA FAZER / DÚVIDAS / PROBLEMAS ENCONTRADOS ***

- problema com double e long continua na hora de imprimir mas está lendo corretamente