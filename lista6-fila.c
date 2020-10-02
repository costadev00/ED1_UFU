/*

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int item[MAX], inicio, fim;
} Fila;

void inicia(Fila *F);
int insere(Fila *F, int x);
int remover(Fila *F, int *x);

int main()
{
    Fila F1;

    int retorno, valor;
    inicia(&F1);

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &valor);
        retorno = insere(&F1, valor);
        if (retorno == 1)
        {
            printf("%d inserido na fila com sucesso!\n", valor);
        }
        else
        {
            printf("Impossivel inserir, a fila esta cheia\n");
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        retorno = remover(&F1, &valor);
        if (retorno == 1)
        {
            printf("Valor removido %d\n", valor);
        }
        else
        {
            printf("Fila acabou\n");
        }
    }
    return 0;
}

void inicia(Fila *F)
{
    (*F).inicio = 0;
    (*F).fim = 0;
}

int insere(Fila *F, int x)
{
    if ((*F).fim == MAX)
    {
        return 0;
    }
    else
    {
        (*F).item[(*F).fim] = x;
        (*F).fim++;
        return 1;
    }
}
int remover(Fila *F, int *x)
{
    if ((*F).inicio == (*F).fim)
    {
        return 0;
    }
    else
    {
        *x = (*F).item[((*F).inicio)];
        (*F).inicio++;
        return 1;
    }
}