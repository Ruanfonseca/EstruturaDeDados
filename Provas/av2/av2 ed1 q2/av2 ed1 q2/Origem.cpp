#include<stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#define MAX_TAREFAS 100

using namespace std;

struct Tarefa {
    int dia;
    int multa;
};

bool compara(Tarefa a, Tarefa b) {

    if (a.dia == b.dia)
    {
        return a.multa > b.multa;
    }
    return a.dia < b.dia;
}

int main() {
    int n, i;
    cout << "Numero de tarefas: ";
    cin >> n;
    Tarefa* tarefas= new Tarefa[n];

    for (i = 0; i < n; i++) {
        cout << endl;
        cout << "Prazo da tarefa " << i + 1 << " (dias): ";
        cin >> tarefas[i].dia;
        cout << "multa da tarefa " << i + 1 << ": ";
        cin >> tarefas[i].multa;
    }

    sort(tarefas, tarefas + n, compara);

    int dias_trabalhados = 1, multa = 0;
    for (i = 0; i < n; i++) {

        if (dias_trabalhados <= tarefas[i].dia)
        {
            dias_trabalhados += 1;
        }
        else {
            multa += (dias_trabalhados - tarefas[i].dia) * tarefas[i].multa;
            dias_trabalhados += 1;
        }
    }

    printf("\nMulta total: %d\n", multa);
    return 0;
}
