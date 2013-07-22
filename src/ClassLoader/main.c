#include <stdio.h>
#include "ClassStructure.h"
#include "ClassLoader.h"

int main(int argc, char *argv[])
{
	char *classpath;
	ClassFile *class;

	if(argc != 3)
	{
		printf("ERRO: formato de entrada invalido.Use:\nnome_programa opcao_imprimir arquivo.class\n\nA opcao_imprimir pode ser 0 caso nao queira imrpimir o ClassFile ou 1 caso queira\n");
		exit(1);
	}
	else
	{
		classpath = argv[2];
		class = readClass(classpath);
		if(atoi(argv[1]) == 0)
		{

		}
		else if(atoi(argv[1]) == 1)
		{
			printClass(class, classpath);
		}
		else
		{
			printf("ERRO: opcao_imprimir errada. Use 0 (para NAO imprimir) ou 1 (para imprimir\n");
			exit(1);
		}
	}
	return 0;
}