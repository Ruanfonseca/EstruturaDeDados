#include<iostream>
#include "Pilha.h"

using namespace std;


//constrututor // stack
pilha::pilha(){
    tamanho = 0;
    estrutura = new TipoItem[Max_itens]; 
} 

//destrutora //~stack
pilha::~pilha(){
    delete [] estrutura;
} 
//verifica se a pilha esta cheia "isfull"
 bool pilha::estacheia(){
    return (tamanho == Max_itens);
 } 
//verifica se a pilha esta vazia "isempty"
 bool pilha::estavazia(){
    return(tamanho == 0);
 } 

//push
 void pilha::inserir(TipoItem item){
  
  if(estacheia()){
    cout <<"a pilha esta cheia po !\n";
  }else{
    estrutura [tamanho]=item;
    tamanho++;
  }

 } 
//pop
 TipoItem pilha::remover(){
    if(estavazia()){
        cout << "a pilha esta vazia!\n";
        return 0;
    }else{
        tamanho--;
        return estrutura[tamanho];
        
    }
 } 
//print
 void pilha::imprimir(){
    cout << "pilha : [";
    for(int i =0 ;i < tamanho;i++){
        cout << estrutura[i] << " ";
    }
    cout << "]\n";
 }

//lenght
 int pilha::qualtamanho(){
    return tamanho;
 } 