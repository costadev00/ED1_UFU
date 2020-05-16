/*
01 – Faça um algoritmo que leia dois números e crie uma função para verifcar qual é o maior
número.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int maior = qualMaior(num1, num2);
    printf("o maior numero é: %d \n", maior);
    return 0;
}
int qualMaior(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}