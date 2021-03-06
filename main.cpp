#include <iostream>
#include <matriz.h>
#include <vetor.h>
#include<omp.h>
#include <time.h>

/**Alunos: Leonardo Perales (C.C.), Pablo Alcantara (C.C.) e Vivian Santos (C.C.)**/

using namespace std;

void executarMatrizes();
void executarCombinacoes();

int main()
{
    int escolha = 0;
    cout << "Escolha:\n\t<1> para multiplicacao de matrizes NxN\n\t<2> para gerar combinacoes de um vetor[N]\n\t<0> Sair\nOpcao: ";
    cin >> escolha;
    do
    {
        switch(escolha)
        {
        case 0:
            cout << "Saindo...\n\n";
            break;
        case 1:
            executarMatrizes();
            break;
        case 2:
            executarCombinacoes();
            break;
        default:
            cout << "Opcao invalida!";
            break;
        }

        if (escolha != 0)
        {
            cout << "\n\n\nEscolha:\n\t<1> para multiplicacao de matrizes NxN\n\t<2> para gerar combinacoes de um vetor[N]\n\t<0> Sair\nOpcao: ";
            cin >> escolha;
        }
    }
    while (escolha != 0);

    return 0;
}

void executarMatrizes()
{
    int tid = 0, n = 0;
    cout << "Digite o valor de N: ";
    cin >> n;
    Matriz mat(n);
    mat.preencherMatriz();
    cout << "\n";
    clock_t Ticks[2];
    Ticks[0] = clock();

    #pragma omp parallel num_threads(n)
    {
        tid=omp_get_thread_num();
        #pragma omp for
        for (int i=0; i< n; i++)
        {
            mat.multiplica(i);
            cout << "Thread #" << tid << " executando na linha #" << i << endl;
        }
    }

    Ticks[1] = clock();

    mat.imprimirMatriz();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTempo gasto: %g ms. \n\n", Tempo);
}

void executarCombinacoes()
{
    int n = 0;
    cout << "Digite o valor de N: ";
    cin >> n;

    Vetor vetor(n);
    vetor.preencherVetor();
    printf("\nCombinacao (%d, %d)\nTotal de combinacoes: %d\n\n", n, vetor.metade, vetor.tamanhoResul);
    clock_t Ticks[2];
    Ticks[0] = clock();
    vetor.gerarCombinacao(n);
    Ticks[1] = clock();
    vetor.imprimirVetor();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms. \n\n", Tempo);
}
