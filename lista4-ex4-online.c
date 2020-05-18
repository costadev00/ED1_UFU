/*
04 – Faça um algoritmo que leia uma frase que tenha mais de 8 caracteres.
Verifique se possui “/”, caso contenha copie o que estiver após a "/" para outra variável.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char frase[50], frase2[50];
    scanf("%[^\n]", &frase);
    int flag = 0, j = 0;
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (flag || frase[i] == '/')
        {
            if (flag)
            {
                frase2[j] = frase[i];
                j++;
            }
            flag = 1;
        }
    }
    printf("%s\n", frase2);
    return 0;
}