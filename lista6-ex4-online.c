/*
04 – Faça um algoritmo que peça a quantidade de elementos para adicionar na pilha, após feita a
leitura retire os números da pilha 1 e coloque os números menores que 100 na pilha 2 e o maiores
ou iguais a 100 na pilha 3 e mostre as pilhas.
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
void verifica(p1, p2, p3);
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
void verifica(pilha *p1, pilha *p2, pilha *p3)
{
    int aux;
    if ((*p1).topo != -1)
    {
        while ((*p1).topo != -1)
        {
            aux = pop(p1);
            if (aux < 100)
            {
                push(p2, aux);
            }
            if (aux >= 100)
            {
                push(p3, aux);
            }
        }
        printf("\n");
    }
}
int main()
{
    int qtd = 0, v1 = 0;
    pilha p1;
    pilha p2;
    pilha p3;
    inicia_pilha(&p1);
    inicia_pilha(&p2);
    inicia_pilha(&p3);
    printf("Digite a quantidade\n");
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &v1);
        push(&p1, v1);
    }
    verifica(&p1, &p2, &p3);
    printf("p2: ");
    mostrar_pilha(p2);
    printf("p3: ");
    mostrar_pilha(p3);
    return 0;
}