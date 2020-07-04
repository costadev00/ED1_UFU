#include <stdio.h>
#include <stdlib.h>

#define Max 5

struct fila
{
    int item[Max], inicio, fim;
};

////////////////////////////////////
void Inicia(struct fila *F);
int Insere(struct fila *F, int X);
int Remove(struct fila *F, int *X);
int mostrarelementos(struct fila F);
////////////////////////////////////

int main()
{
    int n, aux;
    struct fila F;
    Inicia(&F);

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um elemento para inserir na fila: ");
        scanf("%d", &n);
        Insere(&F, n);

        printf("Elementos na fila: ");
        mostrarelementos(F);
        printf("\n\n");
    }

    Remove(&F, &aux);
    printf("Elemento removido: [%d]\n\n", aux);
    printf("\n");

    Remove(&F, &aux);
    printf("Elemento removido: [%d]\n\n", aux);

    printf("Elementos na fila: ");
    mostrarelementos(F);

    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite um elemento para inserir na fila: ");
        scanf("%d", &n);
        Insere(&F, n);

        printf("Elementos na fila: ");
        mostrarelementos(F);
        printf("\n\n");
    }

    return 0;
}
////////////////////////////////////
void Inicia(struct fila *F)
{
    (*F).inicio = 0;
    (*F).fim = 0;
}

int Insere(struct fila *F, int X)
{
    if ((*F).fim == Max)
    {
        printf("Fila cheia!!");
        return 0;
    }
    else
    {
        (*F).item[(*F).fim] = X;
        (*F).fim++;
        return 1;
    }
}

int Remove(struct fila *F, int *X)
{

    if ((*F).inicio == (*F).fim)
    {
        printf("Fila vazia!!");
        return 0;
    }
    else
    {
        *X = (*F).item[(*F).inicio];
        (*F).inicio++;
        return 1;
    }
}

int mostrarelementos(struct fila F)
{

    int aux;

    if (F.fim != F.inicio)
    {
        while (F.fim != F.inicio)
        {
            Remove(&F, &aux);
            printf("[%d]\t", aux);
        }
        return 0;
    }
    else
    {
        return -1;
    }
}
