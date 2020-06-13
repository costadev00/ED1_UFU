/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int total = 0;
    char palavra[100];
    char vogais[11] = "aeiouAEIOU";
    fgets(palavra, 100, stdin);
    for (int i = 0; i < strlen(palavra); i++)
    {
        for (int j = 0; j < strlen(vogais); j++)
        {
            if (palavra[i] == vogais[j])
            {
                total++;
                break;
            }
        }
    }
    printf("Temos um total de %d vogais na palavra/frase %s\n", total, palavra);
    return 0;
}