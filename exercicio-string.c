/*
Fazer um programa que recebe 2 strings e quer saber se uma é permutação da outra. 
Ou seja se tem as msm letras e a msm quantidade de letras... 
Por exemplo se eu escrever amor em uma e Roma em outra, tem q dar q elas são iguais
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int tam1, tam2, cont = 0;
    printf("Digite a primeira palavra\n");
    gets(str1);
    printf("Digite a segunda palavra\n");
    gets(str2);
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    if (tam1 == tam2)
    {
        for (int i = 0; i < tam1; i++)
        {
            for (int j = 0; j < tam2; j++)
            {
                if (str1[i] == str2[j])
                {
                    cont++;
                    str2[j] = 0;
                    break;
                }
            }
        }
        if (cont == tam1)
        {
            printf("Palavras iguais e com as mesmas letras\n");
        }
        else
        {
            printf("Palvras diferentes\n");
        }
        return 0;
    }
}