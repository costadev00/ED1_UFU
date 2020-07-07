#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct celulaLista
{
    int valor;
    struct celulaLista *anterior;
    struct celulaLista *proximo;
} celula;

int menu()
{

    int op;

    printf("\nMenu\n\n");
    printf("1 -Inserir elemento na lista\n");
    printf("2 -Listar elementos inseridos\n");
    printf("3 -Listar elementos positivos\n");
    printf("4 -Listar elementos negativos\n");
    printf("0 -Sair\n");
    printf("Digite uma opcao:\n");
    scanf("%d", &op);
    return op;
}

void insere_lista(celula **inicio, int valor);
void lista_todos(celula *inicio);

void insere_lista(celula **inicio, int valor)
{
    celula *p;

    p = (struct celulaLista *)malloc(sizeof(celula));
    if (!p)
    {
        printf("\nSem Memoria!!!");
    }

    p->valor = valor;
    p->anterior = NULL;
    if (*inicio == NULL)
        p->proximo = NULL;
    else
    {
        p->proximo = *inicio;
        (*inicio)->anterior = p;
    }
    *inicio = p;
}

void lista_todos(celula *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    celula *p;
    p = inicio;

    while (p)
    {
        printf("%d\n", p->valor);
        p = p->proximo;
    }
    printf("\n");
}

void lista_positivos(celula *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    celula *p;
    p = inicio;

    while (p)
    {
        if (p->valor > 0)
        {

            printf("%d\n", p->valor);
        }
        p = p->proximo;
    }
    printf("\n");
}

void lista_negativos(celula *inicio)
{
    if (inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    celula *p;
    p = inicio;

    while (p)
    {
        if (p->valor < 0)
        {

            printf("%d\n", p->valor);
        }
        p = p->proximo;
    }
    printf("\n");
}