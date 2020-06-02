/*
03 – Faça um algoritmo que contenha as seguintes opções: 
1 - Adicionar um valor na pilha
2 - Retirar um número 
3 - Mostrar qual número está no topo da pilha 
4 - Mostrar todos os numeros da pilha 
0 - Sair 

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
    int res, opcao = 0, valor;
    inicia_pilha(&p);
    do
    {
        printf("Digite uma opcao\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor a ser inserido:\n");
            scanf("%d", &valor);
            push(&p, valor);
            break;
        case 2:
            printf("Valor retirado do topo da pilha\n");
            pop(&p);
            break;
        case 3:
            printf("Topo:\n");
            printf("%d\n", p.dados[p.topo]);
            break;
        case 4:
            mostrar_pilha(p);
            break;
        case 0:
            printf("Finish\n");
            break;
        default:
            printf("Digite uma opcao valida\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}
