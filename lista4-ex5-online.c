/*
Faça um algoritmo que tenha uma struct pessoa com os seguintes dados: nome, sexo, profissao e mostre os dados.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    char sexo[2];
    char profissao[50];
} pessoa;

int main()
{
    pessoa p;
    gets(p.nome);
    gets(p.sexo);
    gets(p.profissao);

    printf("Nome: %s \n", p.nome);
    printf("Sexo: %s \n", p.sexo);
    printf("Profissão: %s \n", p.profissao);
    return 0;
}