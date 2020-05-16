/*
07 – Faça um algoritmo que leia uma palavra e que tenha uma função para contar quantas letras
ela contém.
*/
#include <stdio.h>
#include <stdlib.h>
int contarPalavras(char palavra_contar[]);
int main()
{
    char palavra[999];
    int contagem = 0;
    scanf("%s", &palavra);
    contagem = contarPalavras(palavra);
    printf("A palavra contém: %d letras\n", contagem);
    return 0;
}

int contarPalavras(char palavra_contar[])
{
    int cont = 0;
    for (int i = 0; i < palavra_contar[i]; i++)
    {
        cont++;
    }
    return cont;
}