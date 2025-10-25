#include <stdio.h>

int main()
{
    double a11, a12, a13;
    double a21, a22, a23;
    double a31, a32, a33;
    double det;

    printf("Escreva os 9 numeros da matriz 3x3 (linha por linha):\n");

    scanf("%lf %lf %lf", &a11, &a12, &a13);
    scanf("%lf %lf %lf", &a21, &a22, &a23);
    scanf("%lf %lf %lf", &a31, &a32, &a33);

    det = (a11*a22*a33 + a12*a23*a31 + a13*a21*a32) - (a13*a22*a31 + a11*a23*a32 + a12*a21*a33);
    printf("determinante: %.2lf\n", det);

    return 0;
}