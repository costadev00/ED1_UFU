#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct
{
    int topo;
    int dados[max];
} pilha;

///////////////////////////////

void inicia_pilha(pilha *p);

void push(pilha *p, int x);
int pop(pilha *p);

int mostrar_pilha(pilha p);

///////////////////////////////

int main()
{

    pilha p;
    inicia_pilha(&p);

    int aux;

    push(&p, 1);
    printf("\n1 Adicionado\n");

    push(&p, 2);
    printf("\n2 Adicionado\n");

    push(&p, 3);
    printf("\n3 Adicionado\n");

    mostrar_pilha(p);

    aux = pop(&p);
    printf("\n%d foi retirado\n", aux);

    mostrar_pilha(p);

    push(&p, 4);
    printf("\n4 Adicionado\n");

    aux = pop(&p);
    printf("\n%d foi retirado\n", aux);

    push(&p, 5);
    printf("\n5 Adicionado\n\n");

    mostrar_pilha(p);

    return 0;
}

//////////////////////////////

void inicia_pilha(pilha *p)
{
    (*p).topo = -1;
}

void push(pilha *p, int x)
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

int pop(pilha *p)
{
    int valor_retirado;

    if ((*p).topo == -1)
    {
        printf("Pilha vazia\n");
        return (-1);
    }
    else
    {
        valor_retirado = (*p).dados[(*p).topo];
        (*p).topo--;

        return valor_retirado;
    }
}

int mostrar_pilha(pilha p)
{

    int aux;

    if (p.topo != -1)
    {
        while (p.topo != -1)
        {
            aux = pop(&p);
            printf("[%d]\t", aux);
        }
        printf("\n");
    }
    else
    {
        return -1;
    }
}