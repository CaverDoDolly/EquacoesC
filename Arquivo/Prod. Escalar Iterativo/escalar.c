#include "escalar.h"

double produtoEscalar(const double *vetor1, const double *vetor2, int tamanho) {
    double resultado = 0.0; 
    for (int i=0; i < tamanho; i++){
        resultado += vetor1[i] * vetor2[i]; 
    }
    
    return resultado;
}