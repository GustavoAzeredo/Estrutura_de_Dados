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

void InserirElemento1(Lista* l, char n1[], char t1[])
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->nome[6] = n1[6];
	novo->tipo[5] = t1[5];
	novo->valor = 25.50;
	novo->quantidade = 200;
	novo->prox = NULL;
	l = novo;
}

void InserirElemento2(Lista* l, char n2[], char t2[])
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->nome[6] = n2[6];
	novo->tipo[5] = t2[5];
	novo->valor = 26.00;
	novo->quantidade = 250;
	novo->prox = NULL;
	l = novo;
}

void InserirElemento3(Lista* l, char n3[], char t2[])
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->nome[6] = n3[6];
	novo->tipo[5] = t2[5];
	novo->valor = 26.50;
	novo->quantidade = 300;
	novo->prox = NULL;
	l = novo;
}

void InserirElemento4(Lista* l, char n4[], char t1[])
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->nome[6] = n4[6];
	novo->tipo[5] = t1[5];
	novo->valor = 27.00;
	novo->quantidade = 350;
	novo->prox = NULL;
	l = novo;
}

void InserirElemento5(Lista* l, char n5[], char t1[])
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->nome[6] = n5[6];
	novo->tipo[5] = t1[5];
	novo->valor = 27.50;
	novo->quantidade = 400;
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

float PegarValor()
{
	float a;

		printf("Buscar por valor menor ou igual a:\n");
			scanf("%f",&a);

	return a;
}

int PegarQuantidade()
{
	int b;

		printf("Buscar por quantidade menor ou igual a:\n");
			scanf("%d",&b);
	
	return b;
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

void BuscarPorValor(Lista* l, float a)
{
	Lista* busca;

	for (busca = l; busca != NULL; busca = busca->prox){
		if (busca->valor <= a){
			printf("nome: %s\ntipo: %s\nvalor: %f\nquantidade:%d\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
	}
}

void BuscarPorQuantidade(Lista* l, int a)
{
	Lista* busca;

	for (busca = l; busca != NULL; busca = busca->prox){
		if (busca->quantidade <= a){
			printf("nome: %s\ntipo: %s\nvalor: %f\nquantidade:%d\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
	}
}

int main()
{
	Lista* l = NULL;
	char titulo1[6] = "PETR4", titulo2[6] = "VALE5", titulo3[6] = "ITSA4", titulo4[6] = "USIM5", titulo5[6] = "LAME3";
	char tipo1[5] = "vend", tipo2[5] = "comp", string1[6] = "abcde", string2[5] = "fghi";
	int tb = 0, val = 0, qtd = 0;

	InserirElemento1(l, titulo1, tipo1);
	InserirElemento2(l, titulo2, tipo2);
	InserirElemento3(l, titulo3, tipo2);
	InserirElemento4(l, titulo4, tipo1);
	InserirElemento5(l, titulo5, tipo1);

		printf("Digite 1: Para buscar por nome\n");
		printf("Digite 2: Para buscar por tipo\n");
		printf("Digite 3: Para buscar por valor\n");
		printf("Digite 4: Para buscar por quantidade\n");
			scanf("%d",&tb);

				if (tb==1){
					PegarNome(string1);
					BuscarPorNome(l, string1);
				}
				else if (tb==2){
					PegarTipo(string2);
					BuscarPorTipo(l, string2);
				}
				else if (tb==3){
					val = PegarValor();
					BuscarPorValor(l, val);
				}
				else if (tb==4){
					qtd = PegarQuantidade();
					BuscarPorQuantidade(l, qtd);
				}
				else
					printf("Opção Inválida!\n");
	
	return 0;
}
