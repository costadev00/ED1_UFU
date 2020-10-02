/*

*/
#include <stdio.h>
#include <stdlib.h>
#define max 5000
typedef struct fila
{
    int item[max], inicio, fim;
} fila;

int insere(fila *fila, int valor)
{
    if ((*fila).fim == max)
    {
        return -1;
    }
    else
    {
        (*fila).item[(*fila).fim] = valor;
        (*fila).fim++;
        return 1;
    }
}

int remover(fila *F, int *x)
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

// int mostrarElementos(fila *F)
// {

//     int aux;

//     if ((*F).fim != (*F).inicio)
//     {
//         while ((*F).fim != (*F).inicio)
//         {
//             remove(&F, &aux);
//             printf("[%d]\t", aux);
//         }
//         return 0;
//     }
//     else
//     {
//         return -1;
//     }
// }

void inicia(fila *f)
{
    (*f).inicio = 0;
    (*f).fim = 0;
}

int main()
{
    fila *f;
    int opcao, valor, retorno, aux;
    inicia(&f);
    do
    {
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um numero a ser inserido na fila: ");
            scanf("%d", &valor);
            retorno = insere(&f, valor);
            if (retorno == -1)
            {
                printf("A fila está cheia\n");
            }
            else
            {
                printf("%d inserido com sucesso\n", valor);
            }
            break;
        case 2:
            retorno = remover(&f, &valor);
            if (retorno == 1)
            {
                printf("Valor removido %d\n", valor);
            }
            else
            {
                printf("Fila acabou\n");
            }
            break;
        case 3:
            printf("fodase\n");
            // mostrarElementos(&f);
            break;
        default:
            printf("Digite uma opcao valida\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}