#include "vetinput.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 100 

CodigoErro lerVetorDeArquivo(const char *nomeArquivo, double **vetor_out, int *tamanho_out) {
    FILE *arquivo = NULL;
    char linha[MAX_LINHA];
    int tamanho = 0;
    double *vetor = NULL;
    CodigoErro status = SUCESSO;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return ERRO_ARQUIVO_NAO_ENCONTRADO;
    }

    if (fgets(linha, MAX_LINHA, arquivo) == NULL) {
        status = ERRO_ARQUIVO_CORROMPIDO;
        goto fechar_arquivo;
    }
    
    if (sscanf(linha, "%d", &tamanho) != 1 || tamanho <= 0) {
        status = ERRO_ARQUIVO_CORROMPIDO;
        goto fechar_arquivo;
    }

    vetor = (double *)malloc(tamanho * sizeof(double));
    if (vetor == NULL) {
        status = ERRO_ARQUIVO_CORROMPIDO; 
        goto fechar_arquivo;
    }

    for (int i = 0; i < tamanho; i++) {
        if (fgets(linha, MAX_LINHA, arquivo) == NULL) {
            status = ERRO_ARQUIVO_CORROMPIDO;
            free(vetor);
            vetor = NULL;
            goto fechar_arquivo;
        }
        
        if (sscanf(linha, "%lf", &vetor[i]) != 1) {
            status = ERRO_ARQUIVO_CORROMPIDO;
            free(vetor);
            vetor = NULL;
            goto fechar_arquivo;
        }
    }

    *vetor_out = vetor;
    *tamanho_out = tamanho;

fechar_arquivo:
    if (fclose(arquivo) == EOF) {
        if (status == SUCESSO) {
            status = ERRO_FECHAR_ARQUIVO;
        }
    }

    return status;
}