/*
10 – Faça um algoritmo que leia uma frase e que tenha uma função que conte quantas palavras
essa frase possui.
*/
#include <stdio.h>
#include <stdlib.h>
int quantasPalavras(frase);
int main()
{
    char frase[999];
    int resultado;
    fgets(frase, 999, stdin);
    resultado = quantasPalavras(frase);
    printf("Temos %d palavras nessa frase\n", resultado);
    return 0;
}
int quantasPalavras(char frase1[])
{
    int palavras = 0;
    for (int i = 0; i < frase1[i]; i++)
    {
        if (frase1[i] == ' ')
        {
            palavras++;
        }
    }
    palavras++;
    return palavras;
}