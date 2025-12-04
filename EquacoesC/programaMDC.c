#include <stdio.h>

int main()
{
int x, y;
printf("Escolha dois numeros inteiros positivos: ");
scanf("%d %d", &x, &y);

while (y!=0)
{
    int resto = x % y;
    x = y;
    y = resto;
}

printf("Resultado: %d\n", x);
return 0;

}