/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mat[7][7], vet1[7], vet2[7], maior, menor;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            scanf("%d", &mat[i][j]);
            maior = mat[i][j];
            menor = mat[i][j];
        }
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (mat[i][j] >= maior)
            {
                maior = mat[i][j];
            }
            if (menor <= mat[i][j])
            {
                menor = mat[i][j];
            }
        }
        vet1[i] = maior;
        vet2[i] = menor;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("vet1[%d] = %d\n", i, vet1[i]);
        printf("vet2[%d] = %d\n", i, vet2[i]);
    }

    return 0;
}