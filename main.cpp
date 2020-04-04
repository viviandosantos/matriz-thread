#include <iostream>
#include <matriz.h>
#include <thread>

using namespace std;

void exec(Matriz m, int i);

int main()
{
    int N, i;
    cout << "Digite o valor de N: " << endl;
    cin >> N;
    Matriz mat(N);
    std::thread threads[N];
    mat.preencherMatriz();

    for(i = 0; i < N; i++)
    {
        threads[i] = std::thread(exec, mat, i);
        threads[i].join();
    }

    mat.imprimirMatriz();

    return 0;
}

void exec(Matriz m, int i){
    m.multiplica(i);
}
