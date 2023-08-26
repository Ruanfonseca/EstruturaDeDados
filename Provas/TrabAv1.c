#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>


struct Node
{
	char Palavra[60];
	int qtd;
	struct Node *proximo;
	struct Node *anterior;
};
typedef struct Node Node;


struct Lista
{
	struct Node *inicio;
	struct Node *fim;
};
typedef struct Lista Lista;

Node *aux;
Node *anterior;
Node *aux2;

/****************************************************************/
void insere_lista(Lista *li, int num, char palavra[])
{

	Node *novo = (Node*) malloc(sizeof(Node));

	strcpy(novo->Palavra, palavra);
	novo->qtd = num;

	if(li->inicio == NULL)
	{
		li->inicio = novo;
		li->fim = novo;
		li->fim->proximo = NULL;

	}
	else
	{
		anterior = NULL;
		aux = li->inicio;
		while(aux != NULL && novo->qtd > aux->qtd)
		{
			anterior = aux;
			aux = aux->proximo;
		}

		if(anterior == NULL)
		{
			novo->proximo = li->inicio;  /*o novo elemento no atributo prox, apontar� para o elemento que at� ent�o era o primeiro elemento da lista*/
			li->inicio = novo;  /*novo ser� o primeiro elemento da lista, inicio apontar� para o endere�o de novo*/
			/*caso n�o exista nenhum n�mero maior que o novo n�mero*/
		}
		else if(aux == NULL)
		{
			li->fim->proximo = novo;  /*o at� ent�o ultimo elemento da lista no atributo prox apontar� para novo*/
			li->fim = novo; /*novo ser� o ultimo elemento da lista, fim apontar� para o endere�o de novo*/
			li->fim->proximo = NULL; /*aqui fazemos com que o endere�o para o qual fim aponta, no atributo prox receba NULL*/
			/*caso n�mero precise ser inseirido no meio da lista*/
		}
		else
		{
			anterior->proximo = novo; /*o primeiro n�mero menor que o novo inseirido no atributo prox recebe o endere�o de novo*/
			novo->proximo = aux; /*novo no atibuto prox, recebe o endere�o do primeiro n�mero maior que ele*/
		}
	}
	getch();
}


/****************************************************************************************/

/*usando o algoritmo de levestein para compara��o das palavras*/
int comparador(const char *s, const char *t)
{
	int ls = strlen(s), lt = strlen(t);
	int d[ls + 1][lt + 1], i, j;

	for (i = 0; i <= ls; i++)
		for (j = 0; j <= lt; j++)
			d[i][j] = -1;

	int dist(int i, int j)
	{
		if (d[i][j] >= 0) return d[i][j];

		int x;
		if (i == ls)
			x = lt - j;
		else if (j == lt)
			x = ls - i;
		else if (s[i] == t[j])
			x = dist(i + 1, j + 1);
		else
		{
			x = dist(i + 1, j + 1);

			int y;
			if ((y = dist(i, j + 1)) < x) x = y;
			if ((y = dist(i + 1, j)) < x) x = y;
			x++;
		}
		return d[i][j] = x;
	}
	return dist(0, 0);
}

/*********************************************************/
Lista* cria_lista()
{
	/*aloca��o do ponteiro li para controlar a lista*/
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
	{
		/*Se a lista est� inicialmente vazia, inicio e fim apontam para NULL */
		li->fim = NULL;
		li->inicio = NULL;
	}
	return li;
}
/*********************************************************/
void imprime_lista(Lista *li)
{
	if(li->inicio == NULL)
	{
		printf("\nLista Vazia!!");

	}
	else
	{
		aux = li->inicio;
		printf("============= Listagem ================\n");
		do
		{
			printf("Palavra - %s \n", aux->Palavra);
			printf("Quantidade - %d \n", aux->qtd);
			aux = aux->proximo;
			printf("\n");
		}
		while(aux != NULL);
		fflush(stdin);
	}
}

/***********************************************************/
int tamanhoLista(Lista* li)
{
	int tamanho = 0;
	aux = li->inicio;
	do
	{
		aux = aux->proximo;
		tamanho++;
	}
	while(aux != NULL);
	return tamanho;
}

/**************************************************************/

void quicksort_lista(Lista *li)
{
	// caso base: lista vazia ou com um �nico elemento
	if (li->inicio == NULL || li->inicio->proximo == NULL)
	{
		return;
	}

	// selecionar o piv� e particionar a lista em torno dele
	Node *pivo = seleciona_pivo(li,0,(li->inicio-li->fim));
	particionar(li, pivo);

	// ordenar a lista antes do piv�
	Lista lista_antes;
	lista_antes.inicio = li->inicio;
	lista_antes.fim = pivo->anterior;
	quicksort_lista(&lista_antes);

	// ordenar a lista depois do piv�
	Lista lista_depois;
	lista_depois.inicio = pivo->proximo;
	lista_depois.fim = li->fim;
	quicksort_lista(&lista_depois);
}

int seleciona_pivo(Lista *li, int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    Node *pivo = li->inicio;
    int i;
    for (i = inicio; i <= fim; i++)
    {
        if (comparador(pivo->Palavra, li->inicio[i].Palavra) < 0)
        {
            pivo = &li->inicio[i];
        }
    }
    return pivo - li->inicio; // retorna o �ndice do piv�
}

int particionar(Lista *li, int inicio, int fim)
{
    int pivo = seleciona_pivo(li, inicio, fim);
    Node tmp = li->inicio[pivo];
    li->inicio[pivo] = li->inicio[fim];
    li->inicio[fim] = tmp;

    int i = inicio - 1;
    int j;
    for (j = inicio; j < fim; j++)
    {
        if (comparador(li->inicio[j].Palavra, tmp.Palavra) <= 0)
        {
            i++;
            Node t = li->inicio[i];
            li->inicio[i] = li->inicio[j];
            li->inicio[j] = t;
        }
    }
    li->inicio[fim] = li->inicio[i + 1];
    li->inicio[i + 1] = tmp;
    return i + 1;
}
/**************************************************************/

void imprime_lista_Ordenada_OrdemA(Lista* li)
{
	quicksort_lista(li);
	if(li->inicio == NULL)
	{
		printf("\nLista Vazia!!");

	}
	else
	{
		aux = li->inicio;
		printf("============= Listagem ================\n");
		do
		{
			printf("Palavra - %s \n", aux->Palavra);
			printf("Quantidade - %d \n", aux->qtd);
			aux = aux->proximo;
			printf("\n");
		}
		while(aux != NULL);
		fflush(stdin);
	}
}
/**************************************************************/

void pesquisarNoArquivo(Lista* li, char vPalavra[])
{

	FILE *bancodedados;
	bancodedados = fopen("ListadePalavras.txt", " r ");

	char frase[100];
	char aux[104];
	int y = 100, x = 0, quantidade = 0;

	while(fgets(frase, 100, bancodedados) != NULL)
	{
		if(frase[strlen(frase) - 1] == '\n')
			frase[strlen(frase) - 1] = '\0';

		if(comparador(vPalavra, frase) < y)
		{
			y = (comparador(vPalavra, frase));
			strcpy(aux, frase);
			quantidade++;
		}
	}


	if(strcmp(vPalavra, aux) == 0)
	{
		int op = 0, escolha = 0;

		printf("Palavra : %s\n", aux);
		printf("Sua quatidade no arquivo : %d\n", quantidade);


		printf("Inseri na lista (1- SIM ou 0-N�O) ?\n");
		scanf("%i", &escolha);

		if(escolha)
		{
			printf("Inserido !\n\n");
			insere_lista(li, quantidade, vPalavra);
		}

		getchar();
		system("cls");

		printf("Escolha uma op��o:\n");
		printf("1 - Verificar lista ordenada por QUANTIDADE\n");
		printf("2 - Verificar lista ordenada por ORDEM ALFAB�TICA\n");
		printf("0 - Voltar ao menu principal\n");
		printf("->");
		scanf("%d", &op);
		system("cls");

		switch(op)
		{
		case 1:
			imprime_lista(li);
			break;
		case 2:
			imprime_lista_Ordenada_OrdemA(li);
			break;
		case 0:
			Layout(li);
			break;
		default:
			printf("Escolha uma op��o correta !! \n");
			system("pause");
			system("cls");
		}
	}
	else
	{

		puts("Esse item nao existe no banco\n");

	}

	fclose(bancodedados);
	fflush(stdin);
	system("pause");
	system("cls");
	printf("\n");
}


/****************************************************************/
void Layout(Lista* li)
{
	int op;
	char palavraEscolhida[50];

	setlocale(LC_ALL, "Portuguese");

	do
	{
		printf("==============Menu de Op��es================\n");
		printf("1 - Operar com a lista encadeada\n");
		printf("2 - Operar com a Lista Duplamente encadeada\n");
		printf("0 - Sair\n");
		printf("-->");
		scanf("%i", &op);
		system("cls");

		switch(op)
		{
		case 1:
			printf("Digite a palavra\n");
			printf("->");
			scanf("%s", &palavraEscolhida);
			pesquisarNoArquivo(li, palavraEscolhida);
			break;
		case 2:
			printf("Digite a palavra");
			printf("->");
			scanf("%s", &palavraEscolhida);
			//pesquisarNalistaD(palavraEscolhida);
			break;
		case 0:
			exit(0);
		default:
			if(op != 0)
			{
				printf("Escolha uma op��o correta !! \n");
				system("pause");
				system("cls");
			}
		}
	}
	while(op != 4);
}


int main(void)
{
	Lista *li = cria_lista();
	Layout(li);
}
