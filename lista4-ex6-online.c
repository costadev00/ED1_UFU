/*
Faça um algoritmo que contenha a struct funcionário para armazenar os dados de 5 funcionários: nome idade sexo e o salário.
Se o funcionário ganhar menos de R$2000,00 dê um aumento de 50%. Após isso mostre os dados dos funcionários.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[50];
    int idade;
    char sexo;
    double salario;
} funcionario;
void mostrarFuncionario(funcionario fun[]);
int main()
{
    funcionario f[5];
    for (int i = 0; i < 5; i++)
    {
        gets(f[i].nome);
        scanf("%d", &f[i].idade);
        scanf(" %c", &f[i].sexo);
        scanf("%lf", &f[i].salario);
        if (f[i].salario < 2000)
        {
            f[i].salario = f[i].salario + (f[i].salario * 0.50);
        }
    }
    mostrarFuncionario(f);

    return 0;
}
void mostrarFuncionario(funcionario fun[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Nome: %s\n", fun[i].nome);
        printf("Idade: %d\n", fun[i].idade);
        printf("Sexo:%s\n", fun[i].sexo);
        printf("Salario: %lf\n", fun[i].salario);
    }
}