#include <stdio.h>
#include <stdlib.h>

#define Max 8

struct fila
{
    int item[Max];
    int inicio, fim;
};

////////////////////////////////////
void Inicia(struct fila *F);
int Insere(struct fila *F,int X);
int Removetroca(struct fila *F,int *X);
int mostrarelementos(struct fila F);
////////////////////////////////////

int  main()
{
    int n, aux;
    struct fila F;
    Inicia(&F);

    for(int i = 0; i<5; i++)
    {
        printf("Digite um elemento para inserir na fila: ");
        scanf("%d", &n);
        Insere(&F, n);

        printf("Elementos na fila: ");
        mostrarelementos(F);
        printf("\n\n");
    }

    Removetroca(&F,&aux);
    printf("Elemento removido: [%d]\n\n",aux);
    printf("\n");

    Removetroca(&F,&aux);
    printf("Elemento removido: [%d]\n\n",aux);

    printf("Elementos na fila: ");
    mostrarelementos(F);

    for(int i = 0; i<5; i++)
    {
        printf("\nDigite um elemento para inserir na fila: ");
        scanf("%d", &n);
        Insere(&F, n);

        printf("\nElementos na fila: ");
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

int Insere(struct fila *F,int X)
{
    if((*F).fim==Max){
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

int Removetroca(struct fila *F,int *X)
{
    if((*F).inicio==(*F).fim)
        return 0;
    else
    {
        *X = (*F).item[(*F).inicio];
        for(int i=0; i<(*F).fim; i++)
            (*F).item[i] = (*F).item[i+1];
        (*F).fim--;
        return 1;
    }
}

int mostrarelementos(struct fila F)
{

    int aux;

    if(F.fim != F.inicio)
    {
        while(F.fim!=F.inicio)
        {
            Removetroca(&F, &aux);
            printf("[%d]\t",aux);
        }
        return 0;
    }
    else
    {
        return -1;
    }
}
