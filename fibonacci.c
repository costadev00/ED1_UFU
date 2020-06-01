/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long int value[999];
    value[0] = 1;
    value[1] = 1;
    value[2] = 2;
    for (int i = 1; i <= 100; i++)
    {
        value[i] = value[i - 1] + value[i - 2];
        printf("%ld\n\n\n", value[i]);
    }
    return 0;
}