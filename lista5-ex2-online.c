/*
02 – Faça um algoritmo que receba um inteiro e dobra seu valor.Utilize função e ponteiros.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *n;
    scanf("%d", &n);
    int res = dobrarValor(n);
    printf("%d\n", res);
    return 0;
}
int dobrarValor(int n1)
{
    n1 = n1 * 2;
    return n1;
}