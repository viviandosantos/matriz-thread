#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz
{
    public:
        Matriz(int n);
        void preencherMatriz();
        void imprimirMatriz();
        void multiplica(int linha);
        virtual ~Matriz();

    protected:

    private:
        int tamanho;
        int ** m1;
        int ** m2;
        int ** m3;
};

#endif // MATRIZ_H


