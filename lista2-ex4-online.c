/*
4- Faça um algoritmo que preencha um vetor com dez elementos numérios de forma invertida
(9 a 0) e mostre na tela.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet[10], j = 10;

    while (j > 0)
    {
        scanf("%d", &vet[j]);
        j--;
    }
    for (int i = 0; i <= 10; i++)
    {
        printf("%d\n", vet[i]);
    }
    return 0;
}