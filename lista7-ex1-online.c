/*
01 – Faça um algoritmo que leia 10 números, se o número for maior que 0 insira-o na fila, caso
seja menor que 0, retire um elemento da fila, depois mostre-os elementos da fila.
*/
#include <stdio.h>
#include <stdlib.h>

#define Max 10

struct fila
{
    int item[Max];
    int inicio, fim;
};
////////////////////////////////////
void Inicia(struct fila *F);
int Insere(struct fila *F, int X);
int Remove(struct fila *F, int *X);
int mostrarelementos(struct fila F);
////////////////////////////////////
int main()
{
    int n, aux;
    struct fila F;
    Inicia(&F);

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um elemento");
        scanf("%d", &n);
        if (n > 0)
        {
            Insere(&F, n);
        }
        else if (n < 0)
        {
            Remove(&F, &aux);
            printf("Elemento removido: [%d]\n", aux);
        }
    }

    printf("Elementos na fila: ");
    mostrarelementos(F);
    return 0;
}

void Inicia(struct fila *F)
{
    (*F).inicio = 0;
    (*F).fim = 0;
}

int Insere(struct fila *F, int X)
{
    if ((*F).fim == Max)
    {
        printf("Fila cheia!!");
        return 0;
    }
    else
    {
        (*F).item[(*F).fim] = X;
        (*F).fim++;
        return 1;
    }
}

int Remove(struct fila *F, int *X)
{

    if ((*F).inicio == (*F).fim)
    {
        printf("Fila vazia!!");
        return 0;
    }
    else
    {
        *X = (*F).item[(*F).inicio];
        (*F).inicio++;
        return 1;
    }
}

int mostrarelementos(struct fila F)
{

    int aux;

    if (F.fim != F.inicio)
    {
        while (F.fim != F.inicio)
        {
            Remove(&F, &aux);
            printf("[%d]\t", aux);
        }
        return 0;
    }
    else
    {
        return -1;
    }
}