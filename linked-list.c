#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dados;
    struct no *prox;
} noptr;
noptr *inicio;
void insere_lista(noptr *novo, int valor);
void lista_todos();
void remove_lista();

int main()
{
    int recebe = -1;
    inicio = NULL;
    noptr *info;
    do
    {
        printf("Digiteum valor:");
        scanf("%d", &recebe);
        if (recebe != 0)
        {
            info = (struct no *)malloc(sizeof(noptr));
            if (!info)
            {
                printf("\nSemMemoria!!!");
                return;
            }
            insere_lista(info, recebe);
        }
    } while (recebe != 0);
    lista_todos();
    remove_lista();
    lista_todos();
    return 0;
}
void insere_lista(noptr *novo, int valor)
{
    novo->dados = valor;
    if (inicio == NULL)
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = inicio;
    }
    inicio = novo;
}
void remove_lista()
{
    noptr *p;
    if (inicio == NULL)
    {
        printf("\nListaVazia!!!");
        return;
    }
    else
    {
        while (inicio != NULL)
        {
            p = inicio;
            printf("\nValorRemovido: %d", p->dados);
            inicio = p->prox;
            free(p);
        }
    }
}
void lista_todos()
{
    if (inicio == NULL)
    {
        printf("\nListaVazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    while (p)
    {
        printf("\nSaida: %d", p->dados);
        p = p->prox;
    }
    printf("\n");
}