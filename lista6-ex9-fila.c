/*
09 -Escreva um algoritmo que leia um número indeterminado de valores inteiros.
 O valor 0 (zero) finaliza a entrada de dados. Para cada valor lido, determinar se ele e um  número  par  ou impar.  Se  o  número  for  par,  entãoincluí-lo  na  FILA  PAR;  caso contrário, incluí-lo na FILA ÍMPAR. Após o término da entrada de dados, 
retirar um elemento de cada filaalternadamente (iniciando-se pela FILA ÍMPAR)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

typedef struct
{
    int item[MAX], inicio, fim;
} Fila;

typedef struct
{
    int topo;
    int dados[MAX];
} stack;

int push(stack *p, int x)
{
    if ((*p).topo == MAX - 1)
    {
        return -1;
    }
    else
    {
        return (*p).dados[++(*p).topo] = x;
    }
}

int pop(stack *p)
{
    if ((*p).topo == -1)
    {
        return -1;
    }
    else
    {
        return (*p).dados[(*p).topo--];
    }
}

void inicia(Fila *F);
int insere(Fila *F, int x);
int remover(Fila *F, int *x);
int mostrarElementos(Fila F);

int main()
{
    Fila f, f_par, f_impar;
    stack pilha;
    pilha.topo = -1;

    int retorno, valor, aux_par = 0, aux_impar = 0;
    inicia(&f);

    do
    {
        scanf("%d", &valor);
        if (valor == 0)
        {
            break;
        }
        if (valor % 2 == 0)
        {
            retorno = insere(&f_par, valor);
            aux_par++;
        }
        else
        {
            retorno = insere(&f_impar, valor);
            aux_impar++;
        }

        if (retorno == 1)
        {
            printf("%d inserido na fila com sucesso!\n", valor);
        }
        else
        {
            printf("Impossivel inserir, a fila esta cheia\n");
        }
    } while (valor != 0);
    printf("Fila par:\n");
    mostrarElementos(f_par);
    printf("\n");
    printf("Fila impar: \n");
    mostrarElementos(f_impar);
    return 0;
}

int mostrarElementos(Fila F)
{

    int aux;

    if (F.fim != F.inicio)
    {
        while (F.fim != F.inicio)
        {
            remover(&F, &aux);
            printf("[%d]\t", aux);
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

void inicia(Fila *F)
{
    (*F).inicio = 0;
    (*F).fim = 0;
}

int insere(Fila *F, int x)
{
    if ((*F).fim == MAX)
    {
        return 0;
    }
    else
    {
        (*F).item[(*F).fim] = x;
        (*F).fim++;
        return 1;
    }
}
int remover(Fila *F, int *x)
{
    if ((*F).inicio == (*F).fim)
    {
        return 0;
    }
    else
    {
        *x = (*F).item[((*F).inicio)];
        (*F).inicio++;
        return 1;
    }
}