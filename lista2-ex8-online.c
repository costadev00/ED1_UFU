/*
8- Faça um programa que carregue uma matriz 3x3 com números inteiros, some os elementos de
cada linha e armazene em um vetor, depois mostre os resultados.
*/
/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mat[3][3], vet[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vet[i] = mat[i][0] + mat[i][1] + mat[i][2];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}