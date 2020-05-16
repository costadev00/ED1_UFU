/*
02 – Faça um algoritmo que leia uma sequência de números e que tenha uma função que some os
números pares.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3, res;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    res = somarPares(n1, n2, n3);
    printf("%d\n", res);
}
int somarPares(int x1, int x2, int x3)
{
    int acm_par = 0;
    if (x1 % 2 == 0)
    {
        acm_par = acm_par + x1;
    }
    if (x2 % 2 == 0)
    {
        acm_par = acm_par + x2;
    }
    if (x3 % 2 == 0)
    {
        acm_par = acm_par + x3;
    }
    return acm_par;
}