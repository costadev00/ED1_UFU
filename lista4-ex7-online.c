/*
Após isso mostre os dados de todos os funcionários. 07 – Faça um algoritmo que realize o cadastro dos seguintes elementos: nome, idade, sexo
(M ou F). Faça uma função que retorne para a main quantas pessoas do sexo feminino foram
cadastradas e depois mostre na tela esse número.
*/
typedef struct
{
    char nome[50];
    int idade;
    char sexo;
} Pessoa;
// int contaFeminino(int acm_c);
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int acm = 0;
    Pessoa p[2];
    for (int i = 0; i < 2; i++)
    {
        scanf("%s", &p[i].nome);
        scanf("%d", &p[i].idade);
        scanf(" %c", &p[i].sexo);
        if (p[i].sexo == 'F')
        {
            acm++;
        }
    }
    printf("Temos %d pessoas do sexo feminino \n", contaFeminino(acm));

    return 0;
}
int contaFeminino(int acm_c)
{
    return acm_c;
}