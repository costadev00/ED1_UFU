/*
Faça um programa que cadastre nome de pessoas de forma ordenada, use lista duplamente encadeada,
 o programa deve deixar remover uma pessoa qualquer (Exercício 04 da lista 09).

Faça um vídeo demonstrando o uso do debug para testes com 5 (cinco) nomes diferentes iniciando cada um com as letras: M – A – V – C – S.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 10

typedef struct celulaLista
{
    char nome[50];
    struct celulaLista *anterior;
    struct celulaLista *proximo;
} celula;

void insere_lista(celula **inicio, char nome[]);
void remove_lista(celula **inicio);
void lista_todos(celula *inicio);
int main()
{

    char nome[50];
    int opcao;
    celula *inicio;
    inicio = NULL;

    do
    {
        printf("Digite uma opcao:\n\n");
        printf("1 - Inserir um novo nome:\n");
        printf("2 - Ver todos os nomes:\n");
        printf("3 - Remover um nome por pesquisa:\n");
        printf("0 - Encerrar o programa:\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o nome da pessoa\n");
            getchar();
            scanf("%s", nome);
            insere_lista(&inicio, nome);
            break;
        case 2:
            lista_todos(inicio);
            break;
        case 3:
            remove_lista(&inicio);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        }
    } while (opcao != 0);
}

void insere_lista(celula **inicio, char nome[])
{
    celula *novo;
    novo = (struct celulaLista *)malloc(sizeof(celula));
    if (!novo)
    {
        printf("\nSem Memoria!!!");
    }
    else
    {
        strcpy(novo->nome, nome);
        novo->proximo = NULL;
        novo->anterior = NULL;

        if (*inicio == NULL)
        {
            *inicio = novo;
        }
        else
        {
            celula *p = *inicio;

            while (p->proximo && strcmp(novo->nome, p->nome) == 1)
            {
                p = p->proximo;
            }
            if (p == *inicio && strcmp(novo->nome, p->nome) <= 0)
            {
                p->anterior = novo;
                novo->proximo = p;
                *inicio = novo;
            }
            else if (!p->proximo && strcmp(novo->nome, p->nome) == 1)
            {
                p->proximo = novo;
                novo->anterior = p;
            }
            else
            {
                novo->anterior = p->anterior;
                novo->proximo = p;
                p->anterior = novo;
                novo->anterior->proximo = novo;
            }
        }
    }
}

void lista_todos(celula *inicio)
{
    if (inicio == NULL)
    {
        printf("Nao ha nomes na lista!!!\n");
        return;
    }

    celula *p;
    p = inicio;
    while (p)
    {
        printf("%s\n", p->nome);
        p = p->proximo;
    }
    printf("\n");
}

void remove_lista(celula **inicio)
{
    if (*inicio == NULL)
    {
        printf("Lista vazia!");
        return;
    }
    else
    {
        char nome[40];
        printf("Digite o nome para remover: ");
        setbuf(stdin, NULL);
        gets(nome);

        celula *p = *inicio, *ant_aux;

        while (p && p->proximo && (strcmp(p->nome, nome) != 0) && (strcmp(p->nome, nome) != 1))
        {
            ant_aux = p;
            p = p->proximo;
        }
        if (strcmp(p->nome, nome) == 0)
        {
            if (p && p->anterior)
            {
                ant_aux->proximo = p->proximo;
                free(p);
                if (ant_aux->proximo)
                {
                    p = ant_aux->proximo;
                    p->anterior = ant_aux;
                }
            }
            else if (p && !p->anterior)
            {
                *inicio = p->proximo;
                free(p);
                p = *inicio;
                if (p)
                {
                    p->anterior = NULL;
                }
            }
        }
    }
}