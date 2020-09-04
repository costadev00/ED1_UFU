#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct
{
    int topo;
    int dados[max];
} stack;

int push(stack *p, int x)
{
    if ((*p).topo == max - 1)
    {
        return -1;
    }
    else
    {
        return (*p).dados[++(*p).topo] = x;
    }
}

int pop(stack *p)
{
    if ((*p).topo == -1)
    {
        return -1;
    }
    else
    {
        return (*p).dados[(*p).topo--];
    }
}

int main()
{
    stack pilha;
    pilha.topo = -1;
    int x = 1, desemp = 0, val = 0;
    while (x != 0)
    {
        scanf("%d", &x);
        if (x < 100)
        {
            val = push(&pilha, x);
            if (val == -1)
            {
                printf("Nao foi possivel empilhar pois a pilha esta cheia\n");
            }
            else
            {
                printf("Valor empilhado: %d\n", x);
            }
        }
        else
        {
            desemp = pop(&pilha);
            if (desemp == -1)
            {
                printf("Nao foi possivel remover pois a pilha esta vazia\n");
            }
            else
            {
                printf("Valor desempilhado: %d\n", desemp);
            }
        }
    }
    return 0;
}