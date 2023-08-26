#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>

using namespace std;

int moedas[] = { 2, 5, 10, 25, 50 };
int n = 5;

void apresentar_moedas(int valor) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (valor >= moedas[i]) {
            int num = valor / moedas[i];
            valor = valor % moedas[i];
            printf("%d moeda(s) de R$ %d centavos\n", num, moedas[i]);
        }
    }
}

int main() {
    int valor;
    setlocale(LC_ALL, "Portuguese");

    printf("Informe o valor em centavos: ");
    cin >> valor;
    puts("\n");
    if (valor == 0 || valor == 1 || valor == 3) {
        printf("N�o � poss�vel formar o valor com as moedas dispon�veis\n");
    }
    else {
        printf("A menor quantidade de moedas �:\n\n");
        apresentar_moedas(valor);
    }
    return 0;
}