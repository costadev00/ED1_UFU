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
    printf("2 -Retirar elemento da lista\n");
    printf("3 -Listar todos\n");
    printf("0 -Sair\n");
    printf("Digite uma opcao:\n");
    scanf("%d", &op);
    return op;
}

void insere_lista(celula **inicio, int valor);
void remove_lista(celula **inicio);
void lista_todos(celula *inicio);

int main()
{

    int op, valor;

    celula *inicio;
    inicio = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o valor para lista: ");
            scanf("%d", &valor);
            insere_lista(&inicio, valor);
            break;
        case 2:
            remove_lista(&inicio);
            break;
        case 3:
            lista_todos(inicio);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        }
    } while (op != 0);

    return 0;
}

void insere_lista(celula **inicio, int valor)
{
    celula *novo;
    celula *p;

    novo = (struct celulaLista *)malloc(sizeof(celula));
    if (!novo)
    {
        printf("\nSem Memoria!!!");
    }

    novo->valor = valor;
    novo->anterior = NULL;
    if (*inicio == NULL)
    {
        p->proximo = NULL;
    }
    else
    {
        while (p->proximo && p->valor < valor)
        {
            p = p->proximo;
        }
        if (p == *inicio && p->valor > valor) //o cod eh menor q todos
        {
            p->anterior = novo;
            novo->proximo = p;
            *inicio = novo;
        }
        else if (!p->proximo && p->valor < valor) //o cod eh maior que todos da lista
        {
            p->proximo = novo;
            novo->anterior = p;
        }
        else //o cod vai entrar no meio da lista
        {
            novo->anterior = p->anterior;
            novo->proximo = p;
            p->anterior = novo;
            novo->anterior->proximo = novo;
        }
    }
    *inicio = p;
}

void remove_lista(celula **inicio)
{
    celula *p;

    if (*inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        p = *inicio;

        *inicio = p->proximo;
        (*inicio)->anterior = NULL;
        free(p);
    }
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
        printf("Lista : %d\n", p->valor);
        p = p->proximo;
    }
    printf("\n");
}