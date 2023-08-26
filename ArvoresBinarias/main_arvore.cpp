#include <iostream>
#include "arvorebinaria.h"

using namespace std;

int main()
{
    ArvoreBinariadeBusca Arvorealunos;
    int opcao, ra, imp;
    string nome;
    bool busca = false;

    do
    {
        cout<<endl;
        cout << "Digite 0 para parar o algoritmo \n";
        cout << "Digite 1 para inserir um elemento \n";
        cout << "Digite 2 para remover um elemento \n";
        cout << "Digite 3 para buscar um elemento \n";
        cout << "Digite 4 para imprimir um elemento \n";
        cin >> opcao;
        cout<<endl;

        if (opcao == 1){
        
            cout << "Digite o nome do aluno : \n";
            cin >> nome;
            cout << "Digite o ra do aluno : \n";
            cin >> ra;
            Aluno aluno(ra, nome);

            if (Arvorealunos.estacheio())
            {
                cout << "Arvore cheia!\n";
            }
            else
            {

                Arvorealunos.inserir(aluno);
            
            }
        }else if(opcao == 2){
            cout << "Digite o ra do aluno : \n";
            cin >> ra;
            
            Aluno aluno(ra," ");

           Arvorealunos.remover(aluno);
        
        
        }else if(opcao == 3){
           
            cout << "Digite o ra do aluno a ser buscado: \n";
            cin >> ra;
            
            Aluno aluno(ra," ");

           Arvorealunos.buscar(aluno,busca);
           
           if (busca)
           {
            cout << "Elemento encontrado : \n";
            cout << "Nome : "<< aluno.obterNome() << endl;
            cout << "Ra  : " << aluno.obterRa() << endl;;
           }else{
            cout << "Elemento não encontrado : \n";
           }
                    
        }else if(opcao == 4){
            cout << "Digite 1 para fazer a impressão em pre Ordem  \n";
            cout << "Digite 2 para fazer a impressão em  Ordem  \n";
            cout << "Digite 3 para fazer a impressão em pos Ordem  \n";
            cin>>imp;

            if(imp == 1){
              cout << "1";
              Arvorealunos.imprimirPreOrdem(Arvorealunos.obterRaiz());
            }else if(imp == 2){
                cout << "2";
            }else{
                cout << "3";
                Arvorealunos.imprimirPosOrdem(Arvorealunos.obterRaiz());
            }
        }
    } while (opcao != 0);
}