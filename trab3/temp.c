#include <stdio.h>

float graus (float);

int main ()
{

	float f, c;	
	printf("Digite em °F: ");
	scanf ("%f", &f);
	c = graus(f);
	printf("%f°C\n", c);
	
}
float graus (float f)
{
	float c;
	c = (5.0f/9.0f)*(f - 32.0f);
	if (c <= -268)
		printf("A temperatura está proxima do zero absoluto\n");

	else if (c >= -5.0f && c <= 5.0f)
			printf("Está proximo da temperatura de congelamento\n");

		else if (c >= 95.0f && c <= 105.0f)
				printf("Está proximo da temperatura de ebulição\n");

	return c;	
}
