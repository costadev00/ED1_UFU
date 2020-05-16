/*
08 – Faça um algoritmo que leia uma palavra e que tenha uma função para copiar essa palavra
para outra variável.
*/
#include <stdio.h>
#include <stdlib.h>
void copiarPalavra(char palavra_copy[]);
int main()
{
    char palavra[999];
    scanf("%s", &palavra);
    copiarPalavra(palavra);
    return 0;
}
void copiarPalavra(char palavra_copy[])
{
    char palavra_done[999];
    for (int i = 0; i < palavra_copy[i]; i++)
    {
        palavra_done[i] = palavra_copy[i];
    }
    printf("A VARIÁVEL COPIADA: %s\n", palavra_done);
}