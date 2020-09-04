/*

*/
#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct
{
    int topo;
    int dados[max];
} stack;

void push(stack *p, int x)
{
    if ((*p).topo == max - 1)
    {
        printf("Pilha cheia\n");
    }
    else
    {
        (*p).topo++;
        (*p).dados[(*p).topo] = x;
    }
}
int pop(stack *p)
{
    if ((*p).topo == -1)
    {
        printf("Pilha Vazia\n");
        return -1;
    }
    else
    {
        (*p).topo--;
        return (*p).dados[(*p).topo];
    }
}
int main()
{
    int x, nr = 0;
    stack pilha1, pilha2, pilha3;
    pilha1.topo = -1;
    pilha2.topo = -1;
    pilha3.topo = -1;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &x);
        push(&pilha1, x);
    }
    for (int i = 0; i < 20; i++)
    {
        nr = pop(&pilha1);
        printf("Elemento removido: %d\n", nr);
        if (nr < 100)
        {
            push(&pilha2, nr);
            printf("%d inserido com sucesso na pilha 2\n", nr);
        }
        else
        {
            printf("%d inserido com sucesso na pilha 3\n", nr);
            push(&pilha3, nr);
        }
    }
    return 0;
}