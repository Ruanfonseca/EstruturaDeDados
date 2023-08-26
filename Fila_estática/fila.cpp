#include <iostream>
#include "fila.h"
using namespace std;

// construtor
fila::fila()
{
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_itens];
}

// destrutor
fila::~fila()
{

    delete[] estrutura;
}

// isEmpty
bool fila::estavazio()
{
    return (primeiro == ultimo);
}

// isFull
bool fila::estacheio()
{
    return ((ultimo - primeiro) == max_itens);
}

// push // enqueue
void fila::inserir(TipoItem item)
{
    if (estacheio())
    {
        cout << "fila cheia\n";
        cout << "Nao pode ser inserido\n";
    }
    else
    {
        estrutura[ultimo % max_itens] = item;
        ultimo++;
    }
}

// pop // dequeue
TipoItem fila::remover()
{
    if (estavazio())
    {
        cout << "fila vazia\n";
        cout << "Nenhum elemento removido !\n";
        return 0;
    }
    else
    {
        primeiro++;
        return estrutura[(primeiro - 1) % max_itens];
    }
}

void fila::imprimir()
{
    cout << "Fila: [ ";
    for (int i = primeiro; i < ultimo; i++)
    {
        cout << estrutura[i % max_itens] << " ,";
    }
    cout << "]\n";
}