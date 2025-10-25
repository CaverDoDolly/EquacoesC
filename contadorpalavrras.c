#include <stdio.h>
#include <string.h>

int main()
{
char texto[101];
int i, cont = 0;

printf("Escreva o texto: ");
fgets(texto, 101, stdin);

for (i=0; i<strlen(texto); i++)
{
    if (texto[i] == ' ')
    {
        cont++;
    }
    
}
    
printf("Total de palavras: %d", cont + 1);
return 0;
}