/*
7- Faça um programa que leia duas matriz 2x2 com números inteiros, faça a soma das posições e
armazene em uma terceira matriz e a mostre na tela.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mat1[2][2], mat2[2][2], mat3[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}