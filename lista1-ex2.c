/*
02  -  Faça  um  algoritmo  que  leia  a  idade  de  uma  pessoa  expressa  em  dias  e  mostre-a expressa em anos, meses e dias. Defina que todos os meses têm 30 dias. 
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int dias = 0, anos = 0, meses = 0;
    printf("Por favor digite abaixo a quantidade de dias\n");
    scanf("%d", &dias);
    while (dias >= 360)
    {
        anos++;
        dias -= 360;
    }
    while (dias >= 30)
    {
        meses++;
        dias -= 30;
    }
    printf("%d ano(s), %d mes(ses), e %d dia(s)\n", anos, meses, dias);

    return 0;
}