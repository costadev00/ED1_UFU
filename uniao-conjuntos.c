/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vetA[5] = {1, 2, 3}, vetB[5] = {2, 3, 4, 5}, vetC[10], j = 0;
    for (int i = 0; i < 3; i++)
    {
        vetC[i] = vetA[i];
        for (j; j < 4; j++)
        {
            if (vetA[i] == vetB[j])
            {
                j++;
            }
            else
            {
                vetC[j] = vetB[j];
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d", &vetC[i]);
    }
    return 0;
}