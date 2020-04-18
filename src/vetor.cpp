#include "vetor.h"
#include <iostream>
#include <stdlib.h>

/**Alunos: Leonardo Perales (C.C.), Pablo Alcantara (C.C.) e Vivian Santos (C.C.)**/

using namespace std;

Vetor::Vetor(int n)
{
    //ctor
    this->tamanho = n;
    this->metade = n / 2;
    this->tamanhoResul = calcularTotalCombinacoes();

    v = new int[n];
    /*resul = new int * [this->tamanhoResul];

    for(int i = 0; i < tamanhoResul; ++i) {
        resul[i] = new int[metade];
    }*/
}

void Vetor::preencherVetor()
{
    int i;
    for(i = 0; i < this->tamanho; i++)
    {
        this->v[i] = rand() % 1001;
    }

    //for(i = 0; i < this->tamanhoResul; i++)
    //{
    //    for(j = 0; j < this->metade; j++)
    //    {
    //        this->resul[i][j] = 0;
    //    }
    //}
}

void Vetor::imprimirVetor()
{
    int i;

    cout << "\nVetor inicial:" << endl;
    for(i = 0; i < this->tamanho; i++)
    {
        cout << this->v[i] <<  "\t";
    }

    //cout << "\n\nResultado:" << endl;
    //for(i = 0; i < this->tamanhoResul; i++)
    //{
    //    cout << "" << endl;
    //    for(j = 0; j < this->metade; j++){
    //        cout << this->resul[i][j] <<  "\t";
    //    }
    //}
    cout << "\n\n";
}

void Vetor::combinacao(int arr[], int data[], int start, int end, int index, int r)
{
  int i, j;

  if (index == r)
  {
    for (j=0; j<r; j++)
      printf("%d ", data[j]);
    printf("\n");
    return;
  }

  for (i=start; i<=end && end-i+1 >= r-index; i++)
  {
    data[index] = arr[i];
    combinacao(arr, data, i+1, end, index+1, r);
  }
}

void Vetor::gerarCombinacao(int arr[], int n, int r)
{
  int data[r];

  combinacao(arr, data, 0, n-1, 0, r);
}

int Vetor::calcularTotalCombinacoes()
{
    int c = fatorial(this->tamanho) / (fatorial(this->metade) * fatorial(this->tamanho - this->metade));
     return c;
}

int Vetor::fatorial(int n)
{
    int fat;
    for(fat = 1; n > 1; n = n - 1)
    {
        fat = fat * n;
    }
    return fat;
}

Vetor::~Vetor()
{
    //dtor
    this->v = nullptr;
}
