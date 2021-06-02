#include<stdio.h>

void Fatorial();

int main(int argc, char const *argv[])
{
	int numero = 0;
	int n = 0;

	printf("\nDigite um número inteiro positivo: ");
	scanf("%d",&numero);

		n = numero;
		Fatorial(&numero);

		printf("\nO fatorial de %d é %d", n, numero);
		printf("\n\n");
	return 0;
}

void Fatorial(int* num)
{
	int fat = 0;
	int i = 0;

	fat = *num;
	i = *num - 1;

	if (*num==1||*num==0)
		fat = 1;
	
	else
		while(i>0)
		{
			fat = fat * i;
			i--;
		}
	
	*num = fat;
}