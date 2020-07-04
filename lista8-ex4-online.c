/*
04 – Faça um algoritmo que contenha as seguintes opções: 
1 - Inserir um nome na lista 
2 - Retirar um nome da lista 
3 - Mostrar quantos nome a lista possui 
4 - Mostrar todos os nome da lista 0 - Sair 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no
{
    char *nome;
    struct no *proximo;
} no;
no *inicio;

void inserefim(no *novo, char valor)
{
    no *p;
    novo->nome = valor;
    novo->proximo = NULL;
    if (inicio == NULL)
    {
        inicio = novo;
    }
    else
    {
        p = inicio;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
}

void removeinicio()
{
    if (inicio == NULL)
    {
        printf("a lista esta vazia");
    }
    else
    {
        no *p;
        p = inicio;
        printf("valor removido %d\n", p->nome);
        inicio = p->proximo;
        free(p);
    }
}

void mostraQuantidade()
{
    int cont = 0;
    no *p;
    if (inicio == NULL)
    {
        printf("A lista possui 0 nomes\n");
    }
    else
    {
        p = inicio;
        while (p != NULL)
        {
            cont++;
            p = p->proximo;
        }
        printf("A lista possui %d nomes\n", cont);
    }
}

void mostralista()
{
    no *p;
    if (inicio == NULL)
    {
        printf("Lista Vazia");
    }
    else
    {
        p = inicio;
        while (p != NULL)
        {
            puts(p->nome);
            p = p->proximo;
        }
    }
}

int main()
{
    inicio = NULL;
    no *caixa;
    int op;
    char val[100];
    do
    {
        printf("Menu\n1 Adicionar um nome na lista\n2 Remover elemento da lista\n3 Mostrar quantos nomes a lista possui\n4 Mostrar nomes\n0 sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um nome:\n");
            scanf("%s", val);
            caixa = (struct no *)malloc(sizeof(no));
            if (!caixa)
            {
                printf("memoria cheia:");
                return;
            }

            inserefim(caixa, val);
            break;
        case 2:
            removeinicio();
            break;
        case 3:
            mostraQuantidade();
            break;
        case 4:
            mostralista();
            break;
        default:
            printf("opcao invalida ");
            break;
        }
    } while (op != 0);

    return 0;
}