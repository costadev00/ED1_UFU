/*
3- Faça um algoritmo que preencha dois vetores de dez posições cada um, determine e mostre o
terceiro contendo a soma das posições dos dois vetores anteriores.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet1[10], vet2[10], vet3[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vet1[i]);
        scanf("%d", &vet2[i]);
        vet3[i] = vet1[i] + vet2[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("vet3[%d] = %d \n", i, vet3[i]);
    }
    return 0;
}