#include <iostream>
#include <cstdlib>
using namespace std;
struct VectorX
{
    int *vetor;
    int tam;
};
void inicializa(VectorX *vec, int n)
{
    vec->vetor = new int[n];
    vec->tam = n;
}
void finaliza(VectorX *vec)
{
    delete[] vec->vetor;
    vec->tam = 0;
}
void preenche(VectorX *vec)
{
    for (int i = 0; i < vec->tam; i++)
    {
        vec->vetor[i] = rand() % 100;
    }
}

void concatena(VectorX *vec, VectorX *vecAux, VectorX *vecAux1)
{
    int tam1 = vecAux->tam;
    int tam2 = vecAux1->tam;

    for (int i = 0; i < tam1; i++)
    {
        vec->vetor[i] = vecAux->vetor[i];
    }

    for (int i = 0; i < tam2; i++)
    {
        vec->vetor[i + tam1] = vecAux1->vetor[i];
    }
}

void imprime(VectorX *vec)
{
    for (int i = 0; i < vec->tam; i++)
    {
        cout << vec->vetor[i] << " ";
    }
    cout << endl;
}

int main()
{
    VectorX vec1, vec2, vec3;
    int tam1, tam2;
    cin >> tam1 >> tam2;
    srand(time(NULL));
    inicializa(&vec1,tam1);
    inicializa(&vec2,tam2);
    inicializa(&vec3,tam1+tam2);

    preenche(&vec1);
    preenche(&vec2);
    concatena(&vec3,&vec1,&vec2);



    imprime(&vec1);
    imprime(&vec2);
    imprime(&vec3);



    finaliza(&vec1);
    finaliza(&vec2);
    finaliza(&vec3);
    return 0; 
    }