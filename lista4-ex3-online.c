/*
03 – Faça um algoritmo que leia duas palavras, verifique se são diferentes e concatene as duas
palavras, depois mostre a nova palavra formada, se forem iguais mostre “Sao iguais”.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char p1[100], p2[100], new_p[100];
    gets(p1);
    gets(p2);

    if (strcmp(p1, p2) != 0)
    {
        strcat(p1, p2);
        printf("%s\n", p1);
    }
    else
    {
        printf("São iguais\n");
    }
    return 0;
}