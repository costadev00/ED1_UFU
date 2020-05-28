/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[7], B[7], C[7][2];
    for (int i = 0; i < 7; i++)
    {
        printf("Preencher o vetor A[%d]", i);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        printf("Preencher o vetor B[%d]", i);
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j = j)
        {
            C[i][j] = A[i];
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
            j++;
            C[i][j] = B[i];
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
            j++;
            // printf("C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 2; j = j)
    //     {
    //         j++;
    //         j++;
    //     }
    // }
    return 0;
}