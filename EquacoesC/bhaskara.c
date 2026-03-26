#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, D, P;
    float x1, x2;

    do
    {
    
    printf("Escreva os valores para a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    D = (pow(b,2)) - (4*a*c);
    printf("Delta igual a: %d\n", D);

    if (a==0) 
    {
        printf("O valor de 'a' deve ser diferente de zero para uma equacao do segundo grau, insira a equacao na forma correta.\n");
    }
    else if (D>0) 
    {
        x1 = ((-1*b) + sqrt(D)) / (2*a);
        x2 = ((-1*b) - sqrt(D)) / (2*a);
        printf("Duas raizes reais:\n X1 = %.2f\n X2 = %.2f\n", x1, x2);
    }
    else if (D == 0) 
    {
        x1 = (-1*b) / (2*a);
        printf("So uma raiz real: X1 = %.2f\n", x1);
    }
    else
    {
        printf("Nao tem raiz real.\n");
    }

    printf("Deseja calcular outra equacao? (Digite qualquer numero para Sim e 0 para Nao): ");
    scanf("%d", &P);
    } while (P!= 0);

    return 0;
}