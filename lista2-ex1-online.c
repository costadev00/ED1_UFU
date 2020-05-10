/*
1- Faça um algoritmo que leia um vetor com 20 posições para números inteiros e mostre somente os
números positivos.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &vet[i]);
        if (vet[i] > 0)
        {
            vet[i] = vet[i];
        }
        else
        {
            vet[i] = 0;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (vet[i] != 0 && vet[i] > 0)
        {
            printf("Número positivo: %d\n", vet[i]);
        }
    }
    return 0;
}