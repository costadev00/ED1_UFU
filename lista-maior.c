#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dados;
    struct no *anterior;
    struct no *proximo;
} noptr;

void insere_lista(noptr **inifunc, noptr *novo, int valor);
int compara_lista(noptr *inicio1, noptr *inicio2, int *qnt);

int main()
{
    int recebe = 1;

    noptr *inicio1;
    inicio1 = NULL;

    noptr *info;

    noptr *inicio2;
    inicio2 = NULL;

    int opcao;
    int qnt_maior;
    int maior;

    do
    {
        printf("Digite uma opcao\n");
        printf("1 - Inserir na lista 1\n");
        printf("2 - Inserir na lista 2\n");
        printf("0 -Terminar programa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            info = (struct no *)malloc(sizeof(noptr));
            if (!info)
            {
                printf("\nSem Memoria!!!");
                return 0;
            }
            printf("Digite um valor: ");
            scanf("%d", &recebe);
            insere_lista(&inicio1, info, recebe);
            break;
        }
        case 2:
        {
            info = (struct no *)malloc(sizeof(noptr));
            if (!info)
            {
                printf("\nSem Memoria!!!");
                return 0;
            }
            printf("Digite um valor: ");
            scanf("%d", &recebe);
            insere_lista(&inicio2, info, recebe);
            break;
        }
        case 0:
        {
            break;
        }

        default:
            printf("Erro! Lista Inexistente.\n");
        }

    } while (opcao != 0);

    maior = compara_lista(inicio1, inicio2, &qnt_maior);

    if (maior == 1)
    {
        printf("\nMaior: Lista 1, com %d elementos\n", qnt_maior);
    }

    else if (maior == 2)
    {
        printf("\nMaior: Lista 2, com %d elementos\n", qnt_maior);
    }

    else
    {
        printf("\nAs listas sao iguais, com %d elementos\n", qnt_maior);
    }
}

void insere_lista(noptr **inifunc, noptr *novo, int valor)
{
    novo->dados = valor;
    novo->anterior = NULL;
    if (*inifunc == NULL)
        novo->proximo = NULL;
    else
    {
        novo->proximo = *inifunc;
        (*inifunc)->anterior = novo;
    }
    *inifunc = novo;
}

int compara_lista(noptr *inicio1, noptr *inicio2, int *qnt)
{
    noptr *p1;
    noptr *p2;

    p1 = inicio1;
    p2 = inicio2;

    int cont1 = 0;
    int cont2 = 0;

    while (p1)
    {
        p1 = p1->proximo;
        cont1++;
    }

    while (p2)
    {
        p2 = p2->proximo;
        cont2++;
    }

    if (cont1 > cont2)
    {
        *qnt = cont1;
        return 1;
    }

    else if (cont1 < cont2)
    {
        *qnt = cont2;
        return 2;
    }

    else
    {
        *qnt = cont2;
        return 3;
    }
}