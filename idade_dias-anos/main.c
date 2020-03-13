#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade_dias, idade_meses, idade_anos;
    scanf("%d", &idade_dias);
    idade_anos = idade_dias/360;
    idade_meses = idade_dias/12;
    printf("a sua idade é %d anos, %d meses, %d dias", idade_anos, idade_meses, idade_dias);
    return 0;
}
