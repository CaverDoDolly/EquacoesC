#include <stdio.h>

int main()
{
int dia, mes, ano;
int NumeroDoDiaNoAno = 0;
int diaspormes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

printf("Digite a data no formato DD MM AAAA: ");
scanf("%d %d %d", &dia, &mes, &ano);
if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0 )){
    diaspormes[2] = 29;
}
for (int i = 1; i < mes; i++){
    NumeroDoDiaNoAno = NumeroDoDiaNoAno + diaspormes[i];
}
NumeroDoDiaNoAno = NumeroDoDiaNoAno + dia;
printf("Resultado: %d\n", NumeroDoDiaNoAno);
return 0;
}