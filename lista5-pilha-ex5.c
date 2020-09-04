/*

*/
#include <stdio.h>
#include <stdlib.h>

#define max 10

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
        printf("Elemento inserido: %d\n", x);
    }
}

int pop(stack *p)
{
    if ((*p).topo == -1)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    else
    {
        return (*p).dados[(*p).topo--];
    }
}
int main()
{
    int x, n, vetres[10] = {0}, cont = 0, res = 0;
    stack pilha;
    pilha.topo = -1;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x);
        push(&pilha, x);
    }
    for (int i = 0; cont < 4;)
    {
        n = pop(&pilha);
        if (n == -1)
        {
            printf("Pilha vazia\n");
            exit(0);
        }
        if (n > 0)

            vetres[cont] = n;
        cont++;
    }
}

for (int i = 0; i < 4; i++)
{
    res += vetres[i];
}
printf("A soma dos 4 elementos positivos eh de: %d\n", res);
return 0;
}