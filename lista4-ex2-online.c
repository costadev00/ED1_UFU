/*
02 – Faça um algoritmo que leia 4 palavras e mostre qual é a maior palavra e quantas letras ela
possui.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char word[4][100];
    int big = -1;

    for (int i = 0; i < 4; i++)
    {
        scanf("%s", word[i]);
        if (big == -1 && i == 0)
        {
            big = strlen(word[i]);
        }
        else if (strlen(word[i]) > big)
        {
            big = strlen(word[i]);
        }
    }
    printf("A(s) maior(es) palavra(s) \n");
    for (int i = 0; i < 4; i++)
    {
        if (strlen(word[i]) == big)
        {
            puts(word[i]);
        }
    }
    printf("Seu tamanho é de: %d\n", big);
    return 0;
}