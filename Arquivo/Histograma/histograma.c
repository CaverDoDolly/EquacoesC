#include <stdio.h>
#include <stdlib.h>

#define MAX_VALOR 256
#define NOME_ARQUIVO "arquivo.txt"

typedef struct No{
	int chave;
	int ocorrencia;
	struct No *prox;
}No;

No *lista = NULL;

void inserir_no(int chave, int ocorrencia){
	No *novo_no =(No*)malloc(sizeof(No));
	if(novo_no == NULL){
		printf("Erro: nao foi possivel alocar memoria.\n");
	}
	novo_no->chave = chave;
	novo_no->ocorrencia = ocorrencia;
	novo_no->prox = lista;
	lista = novo_no;
}

int main(){
	int array_histograma[MAX_VALOR] = {0};
	
	FILE *arquivo = fopen(NOME_ARQUIVO, "r");
	if (arquivo == NULL){
		printf("Erro: nao foi possivel ler o arquivo, verifique se ele existe ou se esta no diretorio correto\n");
		return 1;
	}
	
	int numero_lido;
	while (fscanf(arquivo, "%d", &numero_lido) == 1){
		if (numero_lido >= 0 && numero_lido < MAX_VALOR){
			array_histograma[numero_lido]++;
		}
	}
	fclose(arquivo);
	
	printf("Tratando com as ocorrencias\n");
	for(int i = 0; i<MAX_VALOR; i++){
		if (array_histograma[i] > 0){
			inserir_no(i, array_histograma[i]);
			printf("Chave %3d | Ocorrencias: %d\n", i, array_histograma[i]);
		}
	}
	
	printf("-----Exibicao do Histograma Completo-----\n");
	for (int i=0; i<MAX_VALOR; i++){
		printf("Chave %3d | Ocorrencias: %d\n", i, array_histograma[i]);
	}
	
	No *atual = lista;
	No *proximo;
	
	printf("Liberando memoria...\n");
	while(atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	
	lista=NULL;
	
	return 0;
}