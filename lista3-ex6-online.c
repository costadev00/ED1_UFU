/*
06 – Faça um algoritmo que tenha um menu com as sequintes opções para o usuário escolher:
1) A, B e C em ordem crescente
2) A, B e C em ordem decrescente
O algoritmo deve ler 3 números inteiros (A, B e C) e conter uma função para colocar em
ordem crescente e outra para ordem decrescente.
*/
#include <stdio.h>
#include <stdlib.h>

void ordemCrescente(int vet1[]);
void ordemDecrescente(int vet2[]);

int main()
{
    int vet[3], opcao;
    scanf("%d", &opcao);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &vet[i]);
    }
    if (opcao == 1)
    {
        ordemCrescente(vet);
    }
    else if (opcao == 2)
    {
        ordemDecrescente(vet);
    }
    else
    {
        printf("Entre uma opção válida!\n");
    }
    return 0;
}
void ordemCrescente(int vet1[])
{
    int aux = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (vet1[i] >= vet1[j])
            {
                aux = vet1[i];
                vet1[i] = vet1[j];
                vet1[j] = aux;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", vet1[i]);
    }
}
void ordemDecrescente(int vet2[])
{
    int aux = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (vet2[i] >= vet2[j])
            {
                aux = vet2[i];
                vet2[i] = vet2[j];
                vet2[j] = aux;
            }
        }
    }
    for (int i = 2; i >= 0; i--)
    {
        printf("%d\n", vet2[i]);
    }
}