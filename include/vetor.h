#ifndef VETOR_H
#define VETOR_H


class Vetor
{
    public:
        Vetor(int n);

        int tamanhoResul;
        //int ** resul;
        int tamanho;
        int metade;
        int * v;

        void preencherVetor();
        void imprimirVetor();
        void gerarCombinacao(int arr[], int n, int r);
        int calcularTotalCombinacoes();
        virtual ~Vetor();

    protected:

    private:
        int fatorial(int n);
        void combinacao(int arr[], int data[], int start, int end, int index, int r);
};

#endif // VETOR_H
