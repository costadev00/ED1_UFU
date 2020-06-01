/*
just print to see the magic ;)
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long int n = 0;
    n = 11;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 1111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 11111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 111111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 1111111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 11111111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    n = 111111111;
    printf("%ld x %ld = %ld\n", n, n, n * n);
    return 0;
}