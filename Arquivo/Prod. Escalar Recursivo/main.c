#include <stdio.h>
#include <stdlib.h>
#include "vetinput.h" 
#include "escalar.h"  

void imprimirErroLeitura(CodigoErro erro, const char *nomeArquivo) {
    switch (erro) {
        case ERRO_ARQUIVO_NAO_ENCONTRADO:
            printf("Erro: arquivo %s não foi encontrado.\n", nomeArquivo);
            break;
        case ERRO_ARQUIVO_CORROMPIDO:
            printf("Erro: arquivo %s está corrompido.\n", nomeArquivo);
            break;
        case ERRO_FECHAR_ARQUIVO:
            printf("Erro: arquivo %s não pode ser fechado.\n", nomeArquivo);
            break;
        default:
            printf("Erro desconhecido durante a leitura do arquivo %s.\n", nomeArquivo);
            break;
    }
}

int main() {
    char nomeArq1[100], nomeArq2[100];
    double *vetor1 = NULL;
    double *vetor2 = NULL;
    int tamanho1 = 0;
    int tamanho2 = 0;
    CodigoErro status;
    double produto_escalar; 

    if (scanf("%s", nomeArq1) != 1) {return 1;}
    if (scanf("%s", nomeArq2) != 1) {return 1;}

    status = lerVetorDeArquivo(nomeArq1, &vetor1, &tamanho1);
    if (status != SUCESSO) {
        imprimirErroLeitura(status, nomeArq1);
        return 1;
    }

    status = lerVetorDeArquivo(nomeArq2, &vetor2, &tamanho2);
    if (status != SUCESSO) {
        imprimirErroLeitura(status, nomeArq2);
        if (vetor1 != NULL) {
            free(vetor1);
        }
        return 1;
    }

    if (tamanho1 != tamanho2) {
        printf("Erro: os vetores possuem comprimentos distintos.\n");
        if (vetor1 != NULL) {
            free(vetor1);
        }
        if (vetor2 != NULL) {
            free(vetor2);
        }
        return 1;
    }
    produto_escalar = produtoEscalar(vetor1, vetor2, tamanho1);

    printf("%.3lf\n", produto_escalar);

    if(vetor1 != NULL) {
        free(vetor1);
    }
    if (vetor2 != NULL) {
        free(vetor2);
    }
    
    return 0;
}