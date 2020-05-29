/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mat[3][3];
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
            if (i == j)
            {
                mat[i][j] = mat[i][j] * 2;
            }
            else
            {
                mat[i][j] = mat[i][j] * 3;
            }
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        }
    }
    return 0;
}