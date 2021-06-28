#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista{
	char nome[6];
	char tipo[5];
	float valor;
	int quantidade;
	struct lista* prox;
}Lista;			

void InserirElemento(Lista* l, char n[], char t[], float a, int b)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	strcpy(novo->nome,n);
	strcpy(novo->tipo,t);
	novo->valor = a;
	novo->quantidade = b;
	novo->prox = NULL;
	l = novo;
}

char PegarNome(char str[])
{
	setbuf(stdin,NULL);

		printf("Digite o nome de Título:\n");
			fgets(str,6,stdin);

	return str[6];
}

char PegarTipo(char str[])
{
	setbuf(stdin,NULL);

		printf("Diga o tipo, (comp) para compra e (vend) para venda:\n");
			fgets(str,5,stdin);

	return str[5];
}

void BuscarPorNome(Lista* l, char str[])
{
	Lista* busca;

	for (busca = l; busca != NULL; busca = busca->prox){
		if (!strcmp(str,busca->nome)){
			printf("nome: %s\ntipo: %s\nvalor: %f\nquantidade:%d\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
	}
}

void BuscarPorTipo(Lista* l, char str[])
{
	Lista* busca;

	for (busca = l; busca != NULL; busca = busca->prox){
		if (!strcmp(str,busca->nome)){
			printf("nome: %s\ntipo: %s\nvalor: %f\nquantidade:%d\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
	}
}

int main()
{
	Lista* l = NULL;
	char titulo1[6] = "PETR4", titulo2[6] = "VALE5", titulo3[6] = "ITSA4", titulo4[6] = "USIM5", titulo5[6] = "LAME3";
	char tipo1[5] = "vend", tipo2[5] = "comp", string1[6] = "abcde", string2[5] = "fghi";
	int qtd1 = 200, qtd2 = 250, qtd3 = 300, qtd4 = 350, qtd5 = 400, tb = 0;
	float val1 = 25.5, val2 = 26, val3 = 26.5, val4 = 27, val5 = 27.5;

	InserirElemento(l, titulo1, tipo1, val1, qtd1);
	InserirElemento(l, titulo2, tipo2, val2, qtd2);
	InserirElemento(l, titulo3, tipo2, val3, qtd3);
	InserirElemento(l, titulo4, tipo1, val4, qtd4);
	InserirElemento(l, titulo5, tipo1, val5, qtd5);

		printf("Digite 1: Para buscar por nome\n");
		printf("Digite 2: Para buscar por tipo\n");
			scanf("%d",&tb);

				if (tb==1){
					PegarNome(string1);
					BuscarPorNome(l, string1);
				}
				else if (tb==2){
					PegarTipo(string2);
					BuscarPorTipo(l, string2);
				}
				else
					printf("Opção Inválida!\n");
	
	return 0;
}
