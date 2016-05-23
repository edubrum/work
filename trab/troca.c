#include<stdio.h>
#include<stdlib.h>
void troca(float*, float*);
void troca(float* a,float* b)
{
	float tmp;
	tmp = *a;
	*a= *b;
	*b= tmp;
}
int main(int argc, char* argv[])
{
	float x , y;
	printf("Escreva dois números e os trocarei:\n");
	printf("x=");
	scanf("%f", &x);
	printf("y=");
	scanf("%f", &y);
	printf("x = %.1f, y = %.1f\n", x, y);
	troca(&x,&y);
	printf("x = %.1f, y = %.1f\n", x, y);
	return EXIT_SUCCESS;
}

