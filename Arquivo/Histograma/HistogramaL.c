#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LETRAS 26
#define NOME_ARQUIVO "arquivo2.txt"

typedef struct No{
	char chave;
	int ocorrencia;
	struct No *prox;
}No;

No *lista = NULL;

void inserir_no(char chave, int ocorrencia){
	No *novo_no = (No*)malloc(sizeof(No));
	if (novo_no == NULL){
		printf("Erro: nao foi possivel alocar memoria\n");
		exit(1);
	}
	
	novo_no->chave = chave;
	novo_no->ocorrencia = ocorrencia;
	novo_no->prox = lista;
	lista = novo_no;
}

void liberar_MEM(){
	No *atual = lista;
	No *proximo;
	while(atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	lista = NULL;
}

int main(){
	int array_histograma[MAX_LETRAS] = {0};
	int caractere;
	
	printf("Abrindo e lendo arquivo...\n");
	FILE *arquivo = fopen(NOME_ARQUIVO, "r");
	if(arquivo == NULL){
		printf("Erro: Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while((caractere = fgetc(arquivo)) != EOF){
		if (isalpha(caractere)){
			char letra_normalizada = tolower(caractere);
			int indice = letra_normalizada - 'a';
			array_histograma[indice]++;
		}
	}
	fclose(arquivo);
	
	printf("\n---Trabalhando na lista encadeada---\n");
	for(int i = MAX_LETRAS - 1; i>=0; i--){
		if(array_histograma[i] > 0){
			char letra_chave = 'A' + i;
			inserir_no(letra_chave, array_histograma[i]);
			printf("Chave %c | Ocorrencias: %2d\n", letra_chave, array_histograma[i]);
		}
	}
	printf("---Histograma Completo---\n");
	for (int i=0; i< MAX_LETRAS; i++){
		char letra_chave = 'A' + i;
		printf("Chave %c | Ocorrencias: %2d\n", letra_chave, array_histograma[i]);
	}
	liberar_MEM();
	
	return 0;
}