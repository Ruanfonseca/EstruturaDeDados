#include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No *filhoEsquerda;
    No *filhoDireita;
};

class ArvoreBinariadeBusca{//BST 

private:
   No* raiz;


public:
 ArvoreBinariadeBusca();
 ~ArvoreBinariadeBusca();
 void deletarArvore(No* Noatual);
 No* obterRaiz();
 bool estavazio();
 bool estacheio();
 void inserir(Aluno aluno);
 void remover(Aluno aluno);

 void removerBusca(Aluno aluno,No*& noAtual);
 void deletarNo(No*& noAtual);
 void obterSucessor(Aluno& AlunoSucessor,No* temp);

 void buscar(Aluno aluno,bool busca);
 void imprimirPreOrdem(No* NoAtual);
 void imprimirEmOrdem(No* NoAtual);
 void imprimirPosOrdem(No* NoAtual);
};