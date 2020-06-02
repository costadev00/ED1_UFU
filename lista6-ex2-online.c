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
int mostrar_pilha(pilha p);
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
///////////////////////////////
///////////////////////////////

int main()
{

    pilha p;
    int res, opcao;
    inicia_pilha(&p);

    do
    {
        int valor = 0;
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            push(&p, 1);
        }
        else if (opcao == 2)
        {
            pop(&p);
        }
        else if (opcao == 3)
        {
            valor = mostrar_pilha(p);
            printf("%d\n", valor);
        }
        else if (opcao == 0)
        {
            printf("Finish\n");
        }
        else
        {
            printf("Digite uma opcao valida\n");
        }
    } while (opcao != 0);
    return 0;
}
