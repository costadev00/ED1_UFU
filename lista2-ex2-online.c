/*
2- Faça um algoritmo que preencha um vetor com dez números inteiros, calcule e mostre a
quantidade de números negativos e a soma dos números positivos.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet1[10], acm_neg, soma_pos;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vet1[i]);
        if (vet1[i] < 0)
        {
            acm_neg++;
        }
        if (vet1[i] > 0)
        {
            soma_pos = soma_pos + vet1[i];
        }
    }
    printf("Total de números negativos: %d\n", acm_neg);
    printf("Soma dos números positivos: %d\n", soma_pos);
    return 0;
}