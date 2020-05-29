/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matA[5], matB[5][3], fat = 1, acm = 0, res = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &matA[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        matB[i][0] = matA[i] + 5;
        matB[i][1] = calculaFatorial(matA[i]);
        matB[i][2] = matA[i] * 2;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("matB[%d][0] = %d\n", i, matB[i][0]);
        printf("matB[%d][1] = %d\n", i, matB[i][1]);
        printf("matB[%d][2] = %d\n", i, matB[i][2]);
    }

    return 0;
}
int calculaFatorial(int n)
{
    // int n;
    long fat;
    // printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    // scanf("%d", &n);
    fat = 1;
    while (n > 1)
    {
        fat = fat * n;
        n--;
    }
    return fat;
}