#ifndef VETOR_H
#define VETOR_H


class Vetor
{
    public:
        Vetor(int n);

        int tamanhoResul;
        int ** resul;
        int tamanho;
        int linhaResul;
        int colunaResul;
        int metade;
        int * v;

        void preencherVetor();
        void imprimirVetor();
        void gerarCombinacoes(int i, int tid);
        int calcularTotalCombinacoes();
        virtual ~Vetor();

    protected:

    private:
        int fatorial(int n);
};

#endif // VETOR_H
