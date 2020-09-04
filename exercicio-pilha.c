#include <stdio.h>
#include <stdlib.h>

#define max 5

struct stack
{
    int topo;
    int dados[max];
};

void push(struct stack *p, int x)
{
    if ((*p).topo == max - 1)
    { /* pilha cheia*/
        printf("%s\n", "stack overflow(pilha");
    }
    else
    {
        (*p).dados[++(*p).topo] = x;
    }
}

int pop(struct stack *p)
{
    if ((*p).topo == -1)
    { /* pilha vazia*/
        printf("%s\n", "stack underflow(pilha vazia, impossivel fazer a remocao)");
        return -1;
    }
    else
    {
        return (*p).dados[(*p).topo--];
    }
}

void main()
{
    struct stack pilha;
    pilha.topo = -1;
    push(&pilha, 4);
    push(&pilha, 1);
    push(&pilha, 5);
    printf("\n%d", pop(&pilha));
    getch();
    printf("\n%d", pop(&pilha));
    getch();
    printf("\n%d", pop(&pilha));
    getch();
    push(&pilha, 10);
    printf("\n%d", pop(&pilha));
    getch();
    printf("\n%d", pop(&pilha));
    getch();
}