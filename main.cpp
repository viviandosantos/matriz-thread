#include <iostream>
#include <matriz.h>
#include <vetor.h>
#include<omp.h>

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

    mat.imprimirMatriz();
}

void executarCombinacoes()
{
    int tid = 0, n = 0;
    cout << "Digite o valor de N: ";
    cin >> n;

    Vetor vetor(n);
    vetor.preencherVetor();
    cout << "\nTotal de combinacoes: " << vetor.tamanhoResul << endl;
    cout << "\nMetade: " << vetor.metade << endl;
    //#pragma omp parallel     {
    tid=omp_get_thread_num();
    int x = 0, y;
    for (int i = 0; i < n; i++)
    {
        vetor.resul[x][0] = vetor.v[i];
        cout << "\nx: " << x << endl;
        cout << "\nResul[x][0]: " << vetor.resul[x][0] << endl;
        y = 1;
        for (int j = i + 1; j < n; j++)
        {
            vetor.resul[x][y] = vetor.v[j];
            cout << "\n\ty: " << y << endl;
            cout << "\n\tResul[x][y]: " << vetor.resul[x][y] << endl;
            if (y == vetor.metade - 1 && (x + 1) < vetor.tamanhoResul)
            {
                x++;
                vetor.resul[x][0] = vetor.v[i];
                cout << "\ty chegou na metade! x: " << x << endl;
            }
            else
            {
                y++;
                cout << "\ty nao chegou ainda! y: " << y << endl;
            }
        }
        //}
    }

    vetor.imprimirVetor();
}
