#include "vetor.h"
#include <iostream>
#include <stdlib.h>
#include<omp.h>

/**Alunos: Leonardo Perales (C.C.), Pablo Alcantara (C.C.) e Vivian Santos (C.C.)**/

using namespace std;

Vetor::Vetor(int n)
{
    //ctor
    this->tamanho = n;
    this->metade = n / 2;
    this->tamanhoResul = calcularTotalCombinacoes();
    this->x = 0;
    this->y = 0;

    v = new int[n];
    resul = new int * [this->tamanhoResul];

    for(int i = 0; i < tamanhoResul; ++i)
    {
        resul[i] = new int[metade];
    }
}

void Vetor::preencherVetor()
{
    int i, j;
    for(i = 0; i < this->tamanho; i++)
    {
        this->v[i] = rand() % 1001;
    }

    for(i = 0; i < this->tamanhoResul; i++)
    {
        for(j = 0; j < this->metade; j++)
        {
            this->resul[i][j] = 0;
        }
    }
}

void Vetor::imprimirVetor()
{
    int i, j;

    cout << "\nVetor inicial:" << endl;
    for(i = 0; i < this->tamanho; i++)
    {
        cout << this->v[i] <<  "\t";
    }

    cout << "\n\nResultado:" << endl;
    for(i = 0; i < this->tamanhoResul; i++)
    {
        printf("%*d \b. \t\t", 5, i+1);
        for(j = 0; j < this->metade; j++)
        {
            cout << this->resul[i][j] <<  "\t";
        }
        printf("\n");
    }
    cout << "\n\n";
}

void Vetor::combinacao(int data[], int start, int end, int index)
{
    int i, j;

    y = 0;

    if (index == metade)
    {
        for (j=0; j<metade; j++)
        {
            //printf("%d ", data[j]);
            if (x <= tamanhoResul - 1 && y <= metade - 1)
                resul[x][y] = data[j];
            y++;
        }
        //printf("\n");
        x++;

        return;
    }

    for (i=start; i<=end && end-i+1 >= metade-index; i++)
    {
        data[index] = v[i];
        combinacao(data, i+1, end, index+1);
    }
}

void Vetor::gerarCombinacao(int n)
{
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Thread #%d executando...\n", tid);
        int data[metade];
        combinacao(data, 0, n-1, 0);
    }
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
