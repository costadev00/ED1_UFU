/*
04 – Faça um algoritmo que contenha as seguintes opções: 

1 - Inserir elemento na fila

2 - Retirar elemento da fila

3 - Mostrar elemento que está no início da fila

4 - Mostrar elemento que está no final da fila 

5 - Mostrar quantos elementos a fila possui

6 - Mostrar todos os elementos da fila

0 - Sair

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
int mostraInicio(struct fila F);
int mostraFim(struct fila F);
void qtdElementos(struct fila F);
////////////////////////////////////
int main()
{
    int n, aux, opcao = 0;
    struct fila F;
    Inicia(&F);
    do
    {
        printf("Digite a opcao:\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            scanf("%d", &n);
            Insere(&F, n);
        }
        else if (opcao == 2)
        {
            Remove(&F, &aux);
        }
        else if (opcao == 3)
        {
            mostraInicio(F);
        }
        else if (opcao == 4)
        {
            mostraFim(F);
        }
        else if (opcao == 5)
        {
            qtdElementos(F);
        }
        else if (opcao == 6)
        {
            mostrarelementos(F);
        }

    } while (opcao != 0);

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
        return 0;
    else
    {
        *X = (*F).item[(*F).inicio];
        for (int i = 0; i < (*F).fim; i++)
            (*F).item[i] = (*F).item[i + 1];
        (*F).fim--;
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
int mostraInicio(struct fila F)
{

    int aux;

    if (F.fim != F.inicio)
    {
        printf("[%d]\t", F.item[F.inicio]);
        return 0;
    }
    else
    {
        return -1;
    }
}
int mostraFim(struct fila F)
{
    printf("[%d]\t", F.item[F.fim - 1]);
    return 0;
}
void qtdElementos(struct fila F)
{

    int aux;

    if (F.fim != F.inicio)
    {
        printf("A quantidade de elementos na fila é de : %d", F.fim + F.inicio);
        return 0;
    }
    else
    {
        printf("A fila está vazia\n");
        return -1;
    }
}