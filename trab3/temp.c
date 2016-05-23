#include <stdio.h>

float graus (float);

int main ()
{

	float f, c;
	printf("Digite: ");
	scanf ("%f", &f);
	c = graus(f);
	printf("%f\n", c);
	
}
float graus (float f)
{
	float c;
	c = (5.0/9.0)*(f - 32);
	if (c <= -268)
		printf("A temperatura está proxima do zero absoluto\n");
	else if (c >= -5 && c <= 5)
			printf("Está proximo da temperatura de congelamento\n");

		else if (c >= 95 && c <= 105)
				printf("Está proximo da temperatura de ebulição\n");

	return c;	
}
