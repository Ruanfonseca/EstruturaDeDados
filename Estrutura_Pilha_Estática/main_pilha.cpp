#include<iostream>
#include "Pilha.h"
using namespace std;

int main(){
 pilha pilha1;
 TipoItem item;
 int op;
cout << "Programa que gera pilhas:\n";
 do{
    cout << "digite 0 para da um stop no programa\n";
    cout << "digite 1 para inserir um elemento\n";
    cout << "digite 2 para remover um elemento\n";
    cout << "digite 3 para exibir os elementos da pilha\n";
    cin >> op;
    if(op == 1){
        cout << "digite o numero a ser inserido:\n";
        cin >>item;
        pilha1.inserir(item);
    }else if(op == 2){
         item = pilha1.remover();
         cout << "Elemento removido : "<<item<<endl;
    }else if(op==3){
        pilha1.imprimir();
    }
 }while(op != 0);



    return 0;
}