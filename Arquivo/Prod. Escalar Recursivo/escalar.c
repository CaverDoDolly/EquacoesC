#include "escalar.h"

double produtoEscalar(const double *vetor1, const double *vetor2, int tamanho) {
    if (tamanho <= 0)
    {
        return 0.0;
    }
    
    double produto_atual = vetor1[tamanho - 1] * vetor2[tamanho - 1];
    double produto_resto = produtoEscalar(vetor1, vetor2, tamanho - 1);
    
    return produto_atual + produto_resto;
}