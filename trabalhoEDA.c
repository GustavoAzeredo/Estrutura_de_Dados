#include <stdio.h>

void dados_coletados();
void mergesort();

int main(int argc, char const *argv[])
{
	
	dados_coletados();

	return 0;
}

void dados_coletados()
{
	int dados[]={80,60,70,50,45}, n=5;
	int inicio1=0, meio=0, inicio2=0, final=0;

	final = (n - 1);
	meio = ((inicio1+final)/2);
	inicio2 = (meio + 1);

	mergesort(dados, inicio1, meio, inicio2, final,n);
}

void mergesort(int *idade, int inicio1, int meio, int inicio2, int final, int n)
{
	int aux[n], i=0, j=0, cont=0;

	while(inicio1<=meio && inicio2<=final)
	{
		if (idade[inicio1] <= idade[inicio2])
		{
			aux[i] = idade[inicio1];
			inicio1++;
		}
		else
		{
			aux[i] = idade[inicio2];
			inicio2++;
		}
		i++;
	}

		while(inicio1<=meio)
		{
			aux[i] = idade[inicio1];
			i++;
			inicio1++;
		}

			while(inicio2<=final)
			{
				aux[i] = idade[inicio2];
				i++;
				inicio2++;
			}

				for (int j = 0; j < n; ++j)
				{
					idade[j] = aux[j];
				}

					j=0;
					while(j<=(n-1))
					{
						if (idade[j]<=idade[j+1])
						{
							cont = cont;
						}
						else
						{
							cont++;
						}
					}

						if (cont==0)
						{
							for (j = 0; j < n; ++j)
							{
								printf("%d -",idade[j]);;
							}
						}
}