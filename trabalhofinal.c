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

char PegarNome(char str[])
{
	int tn = 0;
	setbuf(stdin,NULL);

		printf("Digite o nome de Título: ");
			fgets(str,6,stdin);
				tn = strlen(str);
				if (str[tn-1]=='\n')
					str[tn-1]='\0';

	return str[6];
}

char PegarTipo(char str[])
{
	int tn = 0;
	setbuf(stdin,NULL);

		printf("Diga o tipo, (comp) para compra e (vend) para venda: ");
			fgets(str,5,stdin);

				tn = strlen(str);
				if (str[tn-1]=='\n')
					str[tn-1]='\0';


	return str[5];
}

void BuscarPorNome(Lista* l1, char str[])
{
	Lista* busca;

	for (busca = l1; busca != NULL; busca = busca->prox){
		if (!strcmp(str,busca->nome)){
			printf("\nnome: %s\ntipo: %s\nvalor: %.2f\nquantidade:%d\n\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
		
	}
}

void BuscarPorTipo(Lista* l1, char str[])
{
	Lista* busca;

	for (busca = l1; busca != NULL; busca = busca->prox){
		if (!strcmp(str,busca->tipo)){
			printf("\nnome: %s\ntipo: %s\nvalor: %.2f\nquantidade:%d\n\n",busca->nome,busca->tipo,busca->valor,busca->quantidade);
		}
		
	}
}

int main()
{
	Lista *l1 = NULL;
	Lista *l2 = NULL;
	Lista *l3 = NULL;

	char n1[6] = "PETR4", n2[6] = "VALE5", n3[6] = "ITSA4";
	char t1[5] = "vend", t2[5] = "comp";
	char string1[6] = "abcde", string2[5] = "fghi";
	int tb = 0;

	l1 = (Lista*)malloc(sizeof(Lista));
	strncpy(l1->nome,n1,5);
	strncpy(l1->tipo,t1,4);
	l1->valor = 25.50;
	l1->quantidade = 200;

	l2 = (Lista*)malloc(sizeof(Lista));
	strncpy(l2->nome,n2,5);
	strncpy(l2->tipo,t2,4);
	l2->valor = 26.00;
	l2->quantidade = 250;

	l3 = (Lista*)malloc(sizeof(Lista));
	strncpy(l3->nome,n3,5);
	strncpy(l3->tipo,t2,4);
	l3->valor = 26.50;
	l3->quantidade = 300;

	l1->prox = l2;
	l2->prox = l3;
	l3->prox = NULL;

		printf("Digite 1: Para buscar por nome\n");
		printf("Digite 2: Para buscar por tipo\n");
		printf("\n");
		scanf("%d",&tb);
		printf("\n");

			if (tb==1){
				PegarNome(string1);
				BuscarPorNome(l1, string1);
			}
			else if (tb==2){
				PegarTipo(string2);
				BuscarPorTipo(l1, string2);
			}
			else
				printf("Opção Inválida!\n");

				
	return 0;
}