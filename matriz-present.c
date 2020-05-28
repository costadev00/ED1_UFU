/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float A[4][5], n;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%f", &n);
            A[i][j] = n;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("A[%d][%d] = %.2f\n", i, j, A[i][j]);
        }
    }
    return 0;
}