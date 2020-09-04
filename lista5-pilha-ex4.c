/*

*/
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

void mostraElementos(stack p)
{
    while (p.topo != -1)
    {
        if (p.topo == -1)
        {
            break;
        }
        else
        {
            printf("%d\n", p.dados[p.topo]);
            p.topo--;
        }
    }
}
int main()
{
    int n, x, desemp, elem = 0;
    stack pilha;
    pilha.topo = -1;
    do
    {
        printf("Digite uma opcao\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Digite um valor a ser inserido no topo da pilha\n");
            scanf("%d", &x);
            push(&pilha, x);
            break;
        case 2:
            desemp = pop(&pilha);
            printf("Valor desempilhado: %d\n", desemp);
            break;

        case 3:
            printf("O elemento que esta no topo da pilha eh: %d\n", x);
            break;

        case 4:
        {
            mostraElementos(pilha);
        }
        break;
        case 5:
            printf("Obrigado por utilizar nossos servicos\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
            break;
        }
    } while (n != 5);
    return 0;
}