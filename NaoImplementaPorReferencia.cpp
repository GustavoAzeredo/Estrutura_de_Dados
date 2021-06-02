#include<stdio.h>

int soma(int &c, int &d)
{
	int s = 0;

		s = c + d;

	return s;
}

int main(int argc, char const *argv[])
{
	
	int s = 0, a = 2, b = 3;

		s = soma(a,b);

		printf("%d\n", s);

	return 0;
}