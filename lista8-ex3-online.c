/*
3: Faça um algoritmo que contenha as seguintes opções:
1 - Inserir elemento na lista 
2 - Retirar elemento da lista 
3 - Mostrar elemento que está no início da lista 
4 - Mostrar elemento que está no final
da lista 
5 - Mostrar todos os elementos da lista 
0 - Sair
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int dados;
    struct no *proximo;
} no;
no *inicio;

void inserefim(no *novo, int valor)
{
    no *p;
    novo->dados = valor;
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
        printf("valor removido %d\n", p->dados);
        inicio = p->proximo;
        free(p);
    }
}

void mostraprimeiroelemento()
{
    no *p;
    if (inicio == NULL)
    {
        printf("a lista esta vazia");
    }
    else
    {
        p = inicio;
        printf("primeiro elemento %d\n", p->dados);
    }
}
void mostraultimoelemento()
{
    no *p;
    if (inicio == NULL)
    {
        printf("a lista esta vazia");
    }
    else
    {
        p = inicio;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        printf("Ultimo elemento: %d\n", p->dados);
    }
}
void mostralista()
{
    no *p;
    if (inicio == NULL)
    {
        printf("a lista esta vazia");
    }
    else
    {
        p = inicio;
        while (p != NULL)
        {
            printf("%d\t", p->dados);
            p = p->proximo;
        }
    }
}

int main()
{
    inicio = NULL;
    no *caixa;
    int op, val;
    do
    {
        printf("Menu\n1 adicionar elemento no fim\n2 remover elemento do inicio\n3 mostrar primeiro elemento\n4 mostrar ultimo elemento\n5 mostrar lista\n0 sair");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("digite um valor:");
            scanf("%d", &val);
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
            mostraprimeiroelemento();
            break;
        case 4:
            mostraultimoelemento();
            break;
        case 5:
            mostralista();
            break;
        default:
            printf("opcao invalida ");
            break;
        }
    } while (op != 0);

    return 0;
}