/*
01 – Faça um algoritmo que receba quatro notas de um aluno, calcule e mostre a média
aritmética das notas e mensagem de aprovado ou reprovado, considerando para aprovação
média 7. (2,5 pontos).
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    double n1, n2, n3, n4, media;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    scanf("%lf", &n4);
    media = (n1 + n2 + n3 + n4) / 4;
    printf("media = %.2lf\n", media);
    if (media >= 7)
    {
        printf("aprovado\n");
    }
    else
    {
        printf("reprovado\n");
    }
    return 0;
}