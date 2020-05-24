/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet[5] = {0, 1, 2, 3, 4};
    int *ptr;
    ptr = vet;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *ptr);
        ptr++;
    }
    return 0;
}