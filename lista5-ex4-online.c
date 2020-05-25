/*
04 – Faça um algoritmo que aloque 5 posições na memória para números inteiros. Faça a leitura
dos 5 valores, verifique quais são pares e mostre-os.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *v;
    v = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (v[i] % 2 == 0)
        {
            printf("%d\n", v[i]);
        }
    }

    return 0;
}