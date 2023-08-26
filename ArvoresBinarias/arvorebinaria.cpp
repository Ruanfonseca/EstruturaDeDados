#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"

using namespace std;

// construtor
ArvoreBinariadeBusca::ArvoreBinariadeBusca()
{
    raiz = NULL;
}
// destrutor
ArvoreBinariadeBusca::~ArvoreBinariadeBusca()
{
    deletarArvore(raiz);
}

void ArvoreBinariadeBusca::deletarArvore(No *Noatual) {
    if (Noatual != NULL)
    {
       deletarArvore(Noatual->filhoEsquerda);

       deletarArvore(Noatual->filhoDireita);
       
       delete Noatual;
    }
    
}

No *ArvoreBinariadeBusca::obterRaiz()
{
    return raiz;
}

bool ArvoreBinariadeBusca::estavazio()
{
    return (raiz == NULL);
}

bool ArvoreBinariadeBusca::estacheio()
{

    try
    {

        No *temp = new No;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {

        return true;
    }
}

void ArvoreBinariadeBusca::inserir(Aluno aluno)
{

    if (estacheio())
    {
        cout << "A arvore esta cheia";
        cout << "Não foi possivel inserir este elemento\n";
    }
    else
    {

        No *NoNovo = new No;
        NoNovo->aluno = aluno;
        NoNovo->filhoDireita = NULL;
        NoNovo->filhoEsquerda = NULL;

        if (raiz == NULL)
        {
            raiz = NoNovo;
        }
        else
        {
            No *temp = raiz;
            while (temp != NULL)
            {
                if (aluno.obterRa() < temp->aluno.obterRa())
                {
                    if (temp->filhoEsquerda == NULL)
                    {
                        temp->filhoEsquerda = NoNovo;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoEsquerda;
                    }
                }
                else
                {
                    if (temp->filhoDireita == NULL)
                    {
                        temp->filhoDireita = NoNovo;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoDireita;
                    }
                }
            }
        }
    }
}

void ArvoreBinariadeBusca::remover(Aluno aluno)
{
    removerBusca(aluno, raiz);
}

void ArvoreBinariadeBusca::removerBusca(Aluno aluno, No *&noAtual)
{

    if (aluno.obterRa() < noAtual->aluno.obterRa())
    {
        removerBusca(aluno, noAtual->filhoEsquerda);
    }
    else if (aluno.obterRa() > noAtual->aluno.obterRa())
    {

        removerBusca(aluno, noAtual->filhoDireita);
    }
    else
    {
        deletarNo(noAtual);
    }
}

void ArvoreBinariadeBusca::deletarNo(No *&noAtual)
{

    No *temp = noAtual;

    if (noAtual->filhoEsquerda == NULL)
    {
        noAtual = noAtual->filhoDireita;

        delete temp;
    }
    else if (noAtual->filhoDireita == NULL)
    {

        noAtual = noAtual->filhoEsquerda;

        delete temp;
    }
    else
    {

        Aluno AlunoSucessor;
        obterSucessor(AlunoSucessor, noAtual);
        noAtual->aluno = AlunoSucessor;
        removerBusca(AlunoSucessor, noAtual->filhoDireita);
    }
}

void ArvoreBinariadeBusca::obterSucessor(Aluno &AlunoSucessor, No *temp)
{

    temp = temp->filhoDireita;

    while (temp->filhoEsquerda != NULL)
    {

        temp = temp->filhoEsquerda;
    }
    AlunoSucessor = temp->aluno;
}

void ArvoreBinariadeBusca::buscar(Aluno aluno, bool busca)
{

    busca = false;
    No *noAtual = raiz;

    while (noAtual != NULL)
    {
        if (aluno.obterRa() < noAtual->aluno.obterRa())
        {
            noAtual = noAtual->filhoEsquerda;
        }
        else if (aluno.obterRa() > noAtual->aluno.obterRa())
        {

            noAtual = noAtual->filhoDireita;
        }
        else
        {
            busca = true;
            aluno = noAtual->aluno;
            break;
        }
    }
}

void ArvoreBinariadeBusca::imprimirPreOrdem(No *NoAtual)
{
    if (NoAtual != NULL)
    {
        cout << NoAtual->aluno.obterNome() << ":" << endl;
        cout << NoAtual->aluno.obterRa() << endl;
    }else{
        return;
    }
  
    imprimirPreOrdem(NoAtual->filhoEsquerda);
    imprimirPreOrdem(NoAtual->filhoDireita);

}

void ArvoreBinariadeBusca::imprimirEmOrdem(No *NoAtual)
{
  
  
  
    if (NoAtual != NULL && NoAtual->filhoDireita!=NULL &&NoAtual->filhoEsquerda!=NULL)
    {

        imprimirEmOrdem(NoAtual->filhoEsquerda);
        cout << NoAtual->aluno.obterNome() << ":" << endl;
        cout << NoAtual->aluno.obterRa() << endl;
        imprimirEmOrdem(NoAtual->filhoDireita);
    }else{
        return;
    }

}

void ArvoreBinariadeBusca::imprimirPosOrdem(No *NoAtual)
{
    if(NoAtual != NULL){

        imprimirPosOrdem(NoAtual->filhoEsquerda);
     
        imprimirPosOrdem(NoAtual->filhoDireita);
        
        cout << NoAtual->aluno.obterNome() << ":" << endl;
        cout << NoAtual->aluno.obterRa() << endl;
    }else{
        return;
    }
}