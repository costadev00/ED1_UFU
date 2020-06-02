/*
05 – Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um texto terminado por ponto (.), preservando a ordem das palavras. 
Por exemplo, dado o texto: 
ESTE EXERCICIO E MUITO FACIL
A saída deve ser: 
ETSE OICICREXE E OTIUM ETST

*/
#include <stdio.h>
#include <stdlib.h>

#define max 999

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

int main()
{
    pilha p1;
    int j = 0;
    inicia_pilha(&p1);
    char frase[100], saida[100];
    fgets(frase, 100, stdin);
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] != ' ' && frase[i] != '.')
        {
            push(&p1, frase[i]);
        }
        else
        {
            while (p1.topo != -1)
            {
                saida[j] = pop(&p1);
                j++;
            }
            saida[j++] = ' ';
        }
    }
    saida[j++] = '\0';
    puts(saida);
    return 0;
}