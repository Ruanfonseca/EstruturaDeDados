#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int numeroDeOcorrencia;
	struct no* esq;
	struct no* dir;
	int altura;
} No;

int altura(No* no)
{
	if (no == NULL)
		return 0;
	return no->altura;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

No* novoNo(int numeroDeOcorrencia)
{
	No* no = (No*)malloc(sizeof(No));
	no->numeroDeOcorrencia = numeroDeOcorrencia;
	no->esq = NULL;
	no->dir = NULL;
	no->altura = 1;
	return no;
}

No* rotacaoDireita(No* y)
{
	No* x = y->esq;
	No* T2 = x->dir;
	x->dir = y;
	y->esq = T2;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	return x;
}

No* rotacaoEsquerda(No* x)
{
	No* y = x->dir;
	No* T2 = y->esq;
	y->esq = x;
	x->dir = T2;
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	return y;
}

int balanceamento(No* no)
{
	if (no == NULL)
		return 0;
	return altura(no->esq) - altura(no->dir);
}

No* inserir(No* no, int numeroDeOcorrencia)
{
	if (no == NULL)
		return novoNo(numeroDeOcorrencia);
	if (numeroDeOcorrencia < no->numeroDeOcorrencia)
		no->esq = inserir(no->esq, numeroDeOcorrencia);
	else if (numeroDeOcorrencia > no->numeroDeOcorrencia)
		no->dir = inserir(no->dir, numeroDeOcorrencia);
	else
		return no;
	no->altura = 1 + max(altura(no->esq), altura(no->dir));
	int bal = balanceamento(no);
	if (bal > 1 && numeroDeOcorrencia < no->esq->numeroDeOcorrencia)
		return rotacaoDireita(no);
	if (bal < -1 && numeroDeOcorrencia > no->dir->numeroDeOcorrencia)
		return rotacaoEsquerda(no);
	if (bal > 1 && numeroDeOcorrencia > no->esq->numeroDeOcorrencia)
	{
		no->esq = rotacaoEsquerda(no->esq);
		return rotacaoDireita(no);
	}
	if (bal < -1 && numeroDeOcorrencia < no->dir->numeroDeOcorrencia)
	{
		no->dir = rotacaoDireita(no->dir);
		return rotacaoEsquerda(no);
	}
	return no;
}
void imprimirArvoreAVL(No* no, int nivel)
{
	if (no != NULL) {
		imprimirArvoreAVL(no->dir, nivel + 1);
		int i;
		for (i = 0; i < nivel; i++) {
			printf("  ");
		}
		printf("%d\n", no->numeroDeOcorrencia);
		imprimirArvoreAVL(no->esq, nivel + 1);
	}
}


void preOrdem(No* no)
{
	if (no != NULL)
	{
		printf("%d ", no->numeroDeOcorrencia);
		preOrdem(no->esq);
		preOrdem(no->dir);
	}
}
int main()
{
	No* raiz = NULL;
	raiz = inserir(raiz, 10);
	raiz = inserir(raiz, 20);
	raiz = inserir(raiz, 30);
	raiz = inserir(raiz, 40);
	raiz = inserir(raiz, 50);
	raiz = inserir(raiz, 25);
	printf("Pre-Ordem da AVL arvore: ");
	preOrdem(raiz);
	
	printf("Arvore AVL: \n");
	imprimirArvoreAVL(raiz, 0);

	return 0;
}
