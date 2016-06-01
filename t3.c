#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* dados;
	int a, b;
	dados = fopen("dados.txt", "r");
	fscanf(dados, "%d%d", &a,&b);
	while(!feof(dados))
	{
		printf("%d %d\n",a,b);
		fscanf(dados, "%d %d", &a,&b);
	}
	fclose(dados);
	return EXIT_SUCCESS;
}		

