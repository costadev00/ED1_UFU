/*
09 – Faça um algoritmo que leia um número N e que indique quantos valores inteiros e
positivos devem ser lidos a seguir. Para cada valor lido, mostre uma tabela contendo o valor
lido e o fatorial desse valor.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, res = 1, x;
    scanf("%d", &n);
    x = n;
    for (int i = 0; i < n; i++)
    {
        while (x > 1)
        {
            res = res * x;
            printf("%d x %d = %d\n", n, x, res);
            x--;
        }
    }
    return 0;
}