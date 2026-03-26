#include <stdio.h>

int main() 
{
    int a, b, resto;
    printf("Escreva dois numeros: ");
    scanf("%d %d", &a, &b);
    
    int dividendo = a;
    int divisor = b;

    printf("Quocientes: ");
    while (divisor != 0) 
    {
        printf("%d", dividendo / divisor);
        resto = dividendo % divisor;

        dividendo = divisor;
        divisor = resto;
    }

    dividendo = a;
    divisor = b;
    resto = dividendo % divisor;

    printf("\nDividendo e divisor: ");
    while (divisor != 0) 
    {
        printf("(%d,%d) ", dividendo, divisor);
        resto = dividendo % divisor;
        dividendo = divisor;
        divisor = resto;
    }

    dividendo = a;
    divisor = b;
    resto = dividendo % divisor;

    printf("\nRestos: ");
    while (divisor != 0) 
    {
        printf("%d ", resto);
        dividendo = divisor;
        divisor = resto;
        resto = dividendo % divisor;
    }

    printf("\n");
    return 0;
}
