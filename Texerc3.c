#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	int x,y,maior,menor,soma;
	char nomef[51];
	soma = 0;
	printf("Digite o nome do arquivo com extensão:");
	scanf("%s", nomef);
	FILE * arquivo;
	arquivo = fopen(nomef, "x");
	while(!feof(arquivo))
	{
		fscanf(arquivo,"%d%d", &x, &y);
		if(x > y)
		{
			maior = x;
			menor = y;
		}
		else
		{
			maior = y;
			menor = x;
		}
	}	
	printf("Maior da linha: %d", maior);
	soma = soma + menor;
	maior = 0;
	menor = 0;
	printf("A soma dos menores é %d", soma);
	fclose(arquivo);
	return 0;
}
