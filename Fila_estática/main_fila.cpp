#include <iostream>
#include "fila.h"
using namespace std;

int main()
{
    fila fila1;
    int op;
    TipoItem item;
    cout << "Programa que gera filas estatica:\n";
    do
    {
        cout << "digite 0 para da um stop no programa\n";
        cout << "digite 1 para inserir um elemento\n";
        cout << "digite 2 para remover um elemento\n";
        cout << "digite 3 para exibir os elementos da Fila\n";
        cin >> op;
        if (op == 1)
        {
            cout << "digite o numero a ser inserido:\n";
            cin >> item;
            fila1.inserir(item);
            system("cls");
        }
        else if (op == 2)
        {
            item = fila1.remover();
            cout << "Elemento removido : " << item << endl;
        }
        else if (op == 3)
        {
            fila1.imprimir();
        }
    } while (op != 0);

    return 0;
}