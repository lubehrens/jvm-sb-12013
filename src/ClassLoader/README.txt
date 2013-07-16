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

- comentar o código


=> GENERAL INFORMATION
- imprimir o nome do accessFlags (dúvida sobre quais são para imprimir)
FAZER IF COM TODAS AS COMBINAÇÕES


=> CONSTANT POOL
- problema com alguns name and type do fieldref (imprimindo um char a mais do que deveria)
- problema com alguns name and type do methodref (imprimindo um char a mais do que deveria)
- provável problema com alguns name and type do methodref (imprimindo um char a mais do que deveria) achar arquivo com esse tipo de método
- problema com algumas string (imprimindo um char a mais do que deveria)
- problema com escrita de long e double TESTAR USAR DEFAULT NO SWITCH
- problema com alguns name and type class name (imprimindo um char a mais do que deveria)


=> INTERFACES
- não sei o que é para imprimir


=> FIELDS 
- problema com escrita de alguns nomes (imprimindo mais do que deveria)


=> METHODS 
- problema com escrita de alguns nomes (imprimindo mais do que deveria) 
- o que imprimir de coisas especificas?
- imprimir o bytecode em mnemônicos


=> ATTRIBUTES 
- o que é para imprimir?