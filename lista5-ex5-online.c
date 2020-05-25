/*
05 – Faça um algoritmo que leia n caracteres até q o usuário digite ‘.’(ponto final). Depois ao
mostrar coloque um ‘!’ (ponto de exclamação) no final do texto.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *n;
    int i = 0;
    int flag = 0;
    n = (int *)malloc(sizeof(int) * 5);
    do
    {
        flag = 0;
        scanf("%c", &n[i]);
        if (i > 4)
        {
            n = (char *)realloc(n, sizeof(int) * i);
        }
        if (n == NULL)
        {
            printf("Memoria insuficiente\n");
        }
        if (n[i] == '.')
        {
            flag = 1;
        }
        i++;
    } while (flag != 1);
    strcat(n, "!");
    printf("%s\n", n);
    return 0;
}