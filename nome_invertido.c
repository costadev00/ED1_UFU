/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nome[100];
    int tam = 0;
    scanf("%s", nome);
    tam = strlen(nome);
    for (int i = tam; i >= 0; i--)
    {
        printf("%c", nome[i]);
    }
    return 0;
}