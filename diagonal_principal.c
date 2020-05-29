/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mat[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
            }
        }
    }
    return 0;
}