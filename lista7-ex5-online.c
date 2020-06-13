/*
05 – Faça um algoritmo que peça a quantidade de elementos para adicionar na fila, após feita a leitura retire os números da fila 1 e coloque os números menores que 100 
na fila 2 e o maiores ou iguais a 100 na fila 3 e mostre as filas. 
*/
#include <stdio.h>
#include <stdlib.h>
#define Max 999

struct fila
{
    int item[999];
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
    int n, aux, tam_fila = 0;
    struct fila F, F2, F3;
    Inicia(&F);
    printf("Digite o tamanho da fila:\n");
    scanf("%d", &tam_fila);
    for (int i = 0; i < tam_fila; i++)
    {
        printf("Digite um elemento");
        scanf("%d", &n);
        Insere(&F, n);
        if (n < 100)
        {
            Insere(&F2, n);
        }
        else if (n >= 100)
        {
            Insere(&F3, n);
        }
    }
    printf("Elementos na fila 1: \n");
    mostrarelementos(F);
    printf("Elementos na fila 2:\n ");
    mostrarelementos(F2);
    printf("Elementos na fila 3: \n");
    mostrarelementos(F3);
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
            printf("\n");
        }
        return 0;
    }
    else
    {
        return -1;
    }
}