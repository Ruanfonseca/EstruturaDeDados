#include <iostream>
#include "pilhadinamica.h"
#include <cstddef> //para usar o null
using namespace std;

// construtor
PilhaDinamica::PilhaDinamica()
{
    NoTopo = NULL;
}

// destrutor
PilhaDinamica::~PilhaDinamica() {
    No* Notemp;
    while (NoTopo != NULL)
    {
        Notemp = NoTopo;
        NoTopo = NoTopo->proximo;
        delete Notemp;
    }
    
}

// isEmpty
bool PilhaDinamica::estavazio()
{
    return (NoTopo == NULL);
}

// isFull
bool PilhaDinamica::estacheio() {
    No* Nonovo;
    try
    {//se for possivel alocar um novo nó ele retorna falso
        Nonovo = new No;
        delete Nonovo;
        return false;
    }
    catch(bad_alloc exception)
    {//se não for possivel alocar um novo nó ele retorna verdadeiro
        return true;
    }
    
}

// push
void PilhaDinamica::inserir(TipoItem item) {
    if (estacheio())
    {
        cout<<"A pilha esta cheia !!\n";
    }
    else
    {
        No* Nonovo = new No;
        Nonovo->valor = item;
        Nonovo->proximo = NoTopo;
        NoTopo = Nonovo;


    }
    
}

// pop
TipoItem PilhaDinamica::remover() {
    if (estavazio())
    {
        cout<<"A pilha esta vazia !!\n";
    }
    else
    {
        No* Notemp;
        Notemp = NoTopo;
        TipoItem aux = NoTopo->valor;
        NoTopo = NoTopo->proximo;
        delete Notemp;
        return aux;
    }
    
}

void PilhaDinamica::imprimir() {
    No* Notemp = NoTopo;
    
   cout<<"Pilha:[ ";
    while(Notemp!=NULL){
        
        cout<<" - "<< Notemp->valor <<" ";

        Notemp = Notemp->proximo;
    }
    cout<<" ]\n";

}
