#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main()
{
    int s [SIZE], j, total = 0;
<<<<<<< HEAD

	FILE *arquivo;
=======
	FILE *arquivo
>>>>>>> 4d811a7ed9b1b70173fff855f9c499e1f9b4ff8b

    for( j = 0 ; j < SIZE; j++ )
    {
        s[j] = 0;
    }

	arquivo = fopen("nonono.txt", "r");

	s['A']++; //numero de apariçoes das letras
	s['B']++; //numero de apariçoes das letras
	s['A']++; //numero de apariçoes das letras

	fclose(arquivo);

    for( j = 0 ; j < SIZE; j++ )
    {
        total += s[j];
    }

    printf("\n%s%13s\n", "Elemento", "Valor");

    for( j = 0 ; j < SIZE; j++ )
    {
		if(s[j] != 0){
	        printf("%8d%4c%5x%13d\n", j, j, j, s[j]);
					}
    }

    printf("\n%8s%13d\n", "Total", total);

    return EXIT_SUCCESS;
}
