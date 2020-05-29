/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float matA[6], matB[6], matC[6][2];
    for (int i = 0; i < 6; i++)
    {
        scanf("%f", &matA[i]);
        scanf("%f", &matB[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        matC[i][0] = matA[i] * 2;
        matC[i][1] = matA[i] - 5;
        printf("%.2f\n", matC[i][0]);
        printf("%.2f\n", matC[i][1]);
    }
    return 0;
}