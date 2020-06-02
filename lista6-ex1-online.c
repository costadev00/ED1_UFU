/*
01 – Faça um algoritmo que adicione 10 valores na pilha 
e depois mostre a soma desses valores.
*/
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

int pop(pilha *p);
void push(pilha *p, int x);
int mostrar_soma();
///////////////////////////////
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

void inicia_pilha(pilha *p)
{
    (*p).topo = -1;
}
///////////////////////////////
///////////////////////////////

int main()
{

    pilha p;
    inicia_pilha(&p);

    int res;

    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);
    push(&p, 1);

    res = mostrar_soma(p);
    printf("Soma = %d\n", res);
    return 0;
}

int mostrar_soma(pilha p)
{
    int aux;
    int soma = 0;
    if (p.topo != -1)
    {
        while (p.topo != -1)
        {
            aux = pop(&p);
            soma = soma + aux;
            printf("[%d]\t", aux);
        }
        printf("\n");
    }
    else
    {
        return -1;
    }
}