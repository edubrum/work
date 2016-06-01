#include <stdio.h>
#define SIZE 3
 
void mostrar(char m[SIZE][SIZE], int tam)
{
    int i, j;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}
 
int main()
{
    int l, c;
    char mesa[SIZE][SIZE] = {
                {'.', '.', '.'}, 
                {'.', '.', '.'}, 
                {'.', '.', '.'}
        };
 
    mostrar(mesa, SIZE);
 
    printf("Informe sua jogada:");
    scanf("%d,%d", &l, &c);
 
    mesa[l][c] = 'X';
 
    mostrar(mesa, SIZE);
 
    return 0;
}
