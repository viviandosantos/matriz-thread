#ifndef VETOR_H
#define VETOR_H

/**Alunos: Leonardo Perales (C.C.), Pablo Alcantara (C.C.) e Vivian Santos (C.C.)**/

class Vetor
{
    public:
        Vetor(int n);

        int tamanhoResul;
        int ** resul;
        int tamanho;
        int metade;
        int * v;
        int x;
        int y;

        void preencherVetor();
        void imprimirVetor();
        void gerarCombinacao(int n);
        int calcularTotalCombinacoes();
        virtual ~Vetor();

    protected:

    private:
        int fatorial(int n);
        void combinacao(int data[], int start, int end, int index);
};

#endif // VETOR_H
