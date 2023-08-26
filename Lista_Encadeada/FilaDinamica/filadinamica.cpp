#include <iostream>
#include "filadinamica.h"
#include <cstddef> //para usar o null
#include <new>
using namespace std;

filadinamica::filadinamica()
{
    primeiro = NULL;
    ultimo = NULL;

} // construtor

filadinamica::~filadinamica()
{
    No *temp;
    while (primeiro != NULL)
    {
        temp = primeiro;
        primeiro = primeiro->proximo;
        delete temp;
    }
    ultimo = NULL;

} // destrutor

bool filadinamica::estavazio()
{
    return (primeiro == NULL);
} // isEmpty

bool filadinamica::estacheio()
{
    No *temp;
    try
    {
        // procura um espaço na memoria para guardar esse nó, é o que essa linha faz
        temp = new No;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }

} // isFull

void filadinamica::inserir(TipoItem item)
{
    if (estacheio())
    {
        cout << "A fila esta cheia !!\n";
    }
    else
    {
        No *NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NULL;
        if (primeiro == NULL)
        {
            primeiro = NoNovo;
        }
        else
        {
            ultimo->proximo = NoNovo;
        }

        ultimo = NoNovo;
    }
}

TipoItem filadinamica::remover()
{
    if (estavazio())
    {
        cout << "a fila esta vazia !!";
    }
    else
    {
        No *temp = primeiro;
        TipoItem itemAux = primeiro->valor;
        primeiro = primeiro->proximo;
        if (primeiro == NULL)
        {
            ultimo = NULL;
        }
        delete temp;
        return itemAux;
    }

} // dequeue //pop

void filadinamica::imprimir()
{
    No* temp = primeiro;
    cout<<"Fila:[ <-";
    while (temp != NULL)
    {
        cout << temp->valor << " ";
        temp = temp->proximo;
    }
    cout<<" ]\n";
    
}