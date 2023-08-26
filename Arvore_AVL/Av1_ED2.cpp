#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <locale.h>

using namespace std;

struct Arquivo
{
	char nome[50];
	int linha;
	int ocorrencias;
	Arquivo* prox;
};

struct No
{
	char palavra[50];
	Arquivo* arquivos;
	No* esq;
	No* dir;
	int altura;
};

int altura(No* no)
{
	return (no == NULL) ? 0 : no->altura;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

No* novoNo(char* palavra, char* nomeArquivo, int linha)
{
	No* no = new No;
	strcpy(no->palavra, palavra);
	no->arquivos = new Arquivo;
	strcpy(no->arquivos->nome, nomeArquivo);
	no->arquivos->linha = linha;
	no->arquivos->ocorrencias = 1;
	no->arquivos->prox = NULL;
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
	return (no == NULL) ? 0 : altura(no->esq) - altura(no->dir);
}

Arquivo* buscaArquivo(No* no, char* nomeArquivo)
{
	Arquivo* arq = no->arquivos;
	while (arq != NULL)
	{
		if (strcmp(arq->nome, nomeArquivo) == 0)
			return arq;
		arq = arq->prox;
	}
	return NULL;
}

void inserirOcorrencia(No* no, char* nomeArquivo, int linha)
{
	Arquivo* arq = buscaArquivo(no, nomeArquivo);
	if (arq == NULL)
	{
		Arquivo* novoArq = new Arquivo;
		strcpy(novoArq->nome, nomeArquivo);
		novoArq->linha = linha;
		novoArq->ocorrencias = 1;
		novoArq->prox = no->arquivos;
		no->arquivos = novoArq;
	}
	else
	{
		arq->ocorrencias++;
		arq->linha = linha;
	}
}

No* inserir(No* no, char* palavra, char* nomeArquivo, int linha)
{
	if (no == NULL)
		return novoNo(palavra, nomeArquivo, linha);
	if (strcmp(palavra, no->palavra) < 0)
		no->esq = inserir(no->esq, palavra, nomeArquivo, linha);
	else if (strcmp(palavra, no->palavra) > 0)
		no->dir = inserir(no->dir, palavra, nomeArquivo, linha);
	else
	{
		inserirOcorrencia(no, nomeArquivo, linha);
	}
	no->altura = max(altura(no->esq), altura(no->dir)) + 1;
	int fatorBalanceamento = balanceamento(no);
	if (fatorBalanceamento > 1 && strcmp(palavra, no->esq->palavra) < 0)
		return rotacaoDireita(no);
	if (fatorBalanceamento < -1 && strcmp(palavra, no->dir->palavra) > 0)
		return rotacaoEsquerda(no);

	if (fatorBalanceamento > 1 && strcmp(palavra, no->esq->palavra) > 0)
	{
		no->esq = rotacaoEsquerda(no->esq);
		return rotacaoDireita(no);
	}

	if (fatorBalanceamento < -1 && strcmp(palavra, no->dir->palavra) < 0)
	{
		no->dir = rotacaoDireita(no->dir);
		return rotacaoEsquerda(no);
	}

	return no;
}

void imprimirOcorrencias(Arquivo* arquivos)
{
	while (arquivos != NULL)
	{
		cout << "\t" << arquivos->nome << ": linha " << arquivos->linha << ", ocorrencias " << arquivos->ocorrencias << endl;
		arquivos = arquivos->prox;
	}
}

void imprimirArvore(No* raiz)
{
	if (raiz != NULL)
	{
		imprimirArvore(raiz->esq);
		cout << raiz->palavra << ":" << endl;
		imprimirOcorrencias(raiz->arquivos);
		imprimirArvore(raiz->dir);
	}
}

No* processarArquivo(No* raiz, char* nomeArquivo, char* palavraBuscada)
{
	ifstream arquivo(nomeArquivo);
	if (arquivo.is_open())
	{
		char linha[256];
		int numeroLinha = 1;
		while (arquivo.getline(linha, 256))
		{
			char* palavra = strtok(linha, " ,.-"); // Separadores de palavras
			while (palavra != NULL)
			{
				if (strcmp(palavra, palavraBuscada) == 0)
					raiz = inserir(raiz, palavra, nomeArquivo, numeroLinha);
				palavra = strtok(NULL, " ,.-");
			}
			numeroLinha++;
		}
		arquivo.close();
	}
	else
	{
		cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
	}
	return raiz;
}

void pesquisarPalavra(No* raiz, char* palavra)
{
	No* atual = raiz;
	bool encontrada = false;
	while (atual != NULL)
	{
		if (strcmp(palavra, atual->palavra) == 0)
		{
			cout << "Palavra encontrada: " << atual->palavra << endl;
			cout << "Ocorrências:" << endl;
			imprimirOcorrencias(atual->arquivos);
			encontrada = true;
			break; // Removendo o break, o código continua a busca mesmo depois de encontrar a palavra
		}
		if (strcmp(palavra, atual->palavra) < 0)
			atual = atual->esq;
		else
			atual = atual->dir;
	}
	if (!encontrada)
		cout << "Palavra não encontrada." << endl;
}
No* encontrarMinimo(No* no)
{
	while (no->esq != NULL)
		no = no->esq;
	return no;
}

No* deletarNo(No* raiz, char* palavra)
{
	if (raiz == NULL)
		return raiz;

	if (strcmp(palavra, raiz->palavra) < 0)
		raiz->esq = deletarNo(raiz->esq, palavra);
	else if (strcmp(palavra, raiz->palavra) > 0)
		raiz->dir = deletarNo(raiz->dir, palavra);
	else
	{
		if (raiz->esq == NULL || raiz->dir == NULL)
		{
			No* temp = raiz->esq ? raiz->esq : raiz->dir;
			if (temp == NULL)
			{
				temp = raiz;
				raiz = NULL;
			}
			else
				*raiz = *temp;
			delete temp;
		}
		else
		{
			No* temp = encontrarMinimo(raiz->dir);
			strcpy(raiz->palavra, temp->palavra);
			raiz->arquivos = temp->arquivos;
			raiz->dir = deletarNo(raiz->dir, temp->palavra);
		}
	}

	if (raiz == NULL)
		return raiz;

	raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

	int fatorBalanceamento = balanceamento(raiz);

	if (fatorBalanceamento > 1 && balanceamento(raiz->esq) >= 0)
		return rotacaoDireita(raiz);

	if (fatorBalanceamento > 1 && balanceamento(raiz->esq) < 0)
	{
		raiz->esq = rotacaoEsquerda(raiz->esq);
		return rotacaoDireita(raiz);
	}

	if (fatorBalanceamento < -1 && balanceamento(raiz->dir) <= 0)
		return rotacaoEsquerda(raiz);

	if (fatorBalanceamento < -1 && balanceamento(raiz->dir) > 0)
	{
		raiz->dir = rotacaoDireita(raiz->dir);
		return rotacaoEsquerda(raiz);
	}

	return raiz;
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	No* raiz = NULL;
	int opcao = 0;
	char nomeArquivo[50];
	char palavraPesquisada[50];
	while (opcao != 4)
	{
		cout << "Menu:" << endl;
		cout << "1. Buscar palavra" << endl;
		cout << "2. Deletar nó da árvore" << endl;
		cout << "3. Adicionar arquivo" << endl;
		cout << "4. Imprimir arvore" << endl;
		cout << "0. Sair" << endl;
		cout << "Digite sua opção: ";
		cin >> opcao;
		cout << endl;
		switch (opcao)
		{
		case 1:
			cout << "Digite a palavra a ser pesquisada: ";
			cin.ignore();
			cin.getline(palavraPesquisada, 50);
			pesquisarPalavra(raiz, palavraPesquisada);
			break;

		case 2:
			cout << "Digite a palavra a ser deletada: ";
			cin.ignore();
			cin.getline(palavraPesquisada, 50);
			raiz = deletarNo(raiz, palavraPesquisada);
			break;
		case 3:
			cout << "Digite o nome do arquivo a ser adicionado: ";
			cin.ignore();
			cin.getline(nomeArquivo, 50);
			raiz = processarArquivo(raiz, nomeArquivo, palavraPesquisada);
			break;

		case 4:
			cout << "Imprimindo a árvore:" << endl;
			imprimirArvore(raiz);
			break;
		case 0:
			cout << "Fim do programa" << endl;
			return 0;
			break;
		default:
			cout << "Opção inválida. Digite novamente." << endl;
			break;
		}
		cout << endl;

	}
	return 0;
}
