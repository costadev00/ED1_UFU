/*
    φ = 1.618
    😃
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double value[100];
    value[0] = 1;
    value[1] = 1;
    value[2] = 2;
    value[3] = 3;
    for (int i = 1; i <= 100; i++)
    {
        value[i] = value[i - 1] + value[i - 2];
        printf("%.15lf\n\n", value[i - 1] / value[i - 2]);
    }
    return 0;
}