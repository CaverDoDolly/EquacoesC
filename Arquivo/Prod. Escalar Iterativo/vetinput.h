#ifndef VETINPUT_H
#define VETINPUT_H

#include <stdio.h>

typedef enum {
    SUCESSO = 0,
    ERRO_ARQUIVO_NAO_ENCONTRADO,
    ERRO_ARQUIVO_CORROMPIDO,
    ERRO_FECHAR_ARQUIVO
} CodigoErro;

CodigoErro lerVetorDeArquivo(const char *nomeArquivo, double **vetor_out, int *tamanho_out);

#endif