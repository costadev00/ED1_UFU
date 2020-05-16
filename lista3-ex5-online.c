/*
 05 – Faça um algoritmo que leia duas palavras e que tenha uma função que verifica se a primeira
letra de ambas são iguais...
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char palavra1[100], palavra2[100];
    scanf("%s", &palavra1);
    scanf("%s", &palavra2);
    verificaLetra(palavra1, palavra2);
    return 0;
}
void verificaLetra(char word1[100], char word2[100])
{
    if (word1[0] == word2[0])
    {
        printf("A 1ª letra é igual\n");
    }
    else
    {
        printf("A 1ª letra é diferente\n");
    }
}