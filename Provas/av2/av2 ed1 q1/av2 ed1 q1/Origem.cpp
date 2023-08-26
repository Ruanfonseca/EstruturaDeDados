#include <stdio.h>
#include <iostream>
#include <locale.h> 
#define MAX_POSTOS 100
using namespace std;
int main()
{
    int n, m, k, i;
    cout << "numero de postos na estrada: ";
    cin >> k;
    cout << "Tamanho da estrada (km): ";
    cin >> m;
    cout << "Capacidade do carro (km): ";
    cin >> n;
    cout << endl;
    int* p = new int[k];
    for (i = 0; i < k; i++)
    {
        cout << "posicao do posto " << i << " : ";
        cin >> p[i];
    }
    int paradaAtual = 0, paradas = 0, combustivel = n;
    for (i = 0; i < k; i++)
    {
        if (p[i] - paradaAtual > combustivel)
        {
            paradas++;
            combustivel = n;
        }

        combustivel -= p[i] - paradaAtual;
        paradaAtual = p[i];
    }

    if (m - paradaAtual > combustivel)
    {
        paradas++;
    }

    if (n > m)
        cout << endl << "Concluiu sem fazer paradas";

    cout << endl << "paradas -> " << paradas << endl;

    delete[] p;
}
