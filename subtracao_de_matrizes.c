/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[5][3], B[5][3], C[5][3];
    for (int i = 0; i < 5; i++)
    {
        int numero = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("digite o valor de A[%d][%d]\n", i, j);
            scanf("%d", &numero);
            A[i][j] = numero;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int numero = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("digite o valor de B[%d][%d]\n", i, j);
            scanf("%d", &numero);
            B[i][j] = numero;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("A[%d][%d] - B[%d][%d] = %d\n", i, j, i, j, C[i][j]);
        }
    }
    return 0;
}