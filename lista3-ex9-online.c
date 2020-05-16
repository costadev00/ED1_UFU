/*
09 – Faça um algoritmo que leia duas palavras e que tenha uma função para verificar se elas são
iguais ou diferentes, caso sejam iguais essa função deve retornar 0, caso sejam diferente verifique
qual delas contém o maior número de letras, caso seja a primeira palavra retorne -1, caso seja a
segunda retorne 1.
*/
#include <stdio.h>
#include <stdlib.h>
char contarLetras(char palavra3[], char palavra4[]);
int main()
{
    char palavra1[999], palavra2[999];
    scanf("%s", &palavra1);
    scanf("%s", &palavra2);
    contarLetras(palavra1, palavra2);
    return 0;
}
char contarLetras(char palavra3[], char palavra4[])
{
    int cont1 = 0, cont2 = 0;
    for (int i = 0; i < palavra3[i]; i++)
    {
        cont1++;
    }
    for (int i = 0; i < palavra4[i]; i++)
    {
        cont2++;
    }
    if (cont1 > cont2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}