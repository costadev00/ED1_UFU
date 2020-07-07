#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 10

typedef struct celulaLista
{
    char nome[50];
    float nota;
    struct celulaLista *anterior;
    struct celulaLista *proximo;
} celula;

int menu()
{

    int op;

    printf("\nMenu\n\n");
    printf("1 -Cadastrar um aluno\n");
    printf("2 -Listar todos os alunos\n");
    printf("3 -Listar todos os alunos aprovados\n");
    printf("0 -Sair\n");
    printf("Digite uma opcao:\n");
    scanf("%d", &op);
    return op;
}

void insere_lista(celula **inicio, char nome[50], float nota);
void remove_lista(celula **inicio);
void lista_todos(celula *inicio);
void lista_todos_aprovados(celula *inicio);

void insere_lista(celula **inicio, char nome[], float nota)
{
    celula *p;
    p = (struct celulaLista *)malloc(sizeof(celula));
    if (!p)
    {
        printf("\nSem Memoria!!!");
    }

    p->nota = nota;
    strcpy(p->nome, nome);
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
        printf("\n Não há aluno cadastrado!!!");
        return;
    }
    celula *p;
    p = inicio;

    while (p)
    {
        printf("Lista : %s\n", p->nome);
        p = p->proximo;
    }
    printf("\n");
}

void lista_todos_aprovados(celula *inicio)
{
    if (inicio == NULL)
    {
        printf("\n Não há aluno cadastrado!!!");
        return;
    }
    celula *p;
    p = inicio;

    while (p)
    {

        if (p->nota >= 7)
        {

            printf("%s\t", p->nome);
            printf("%.1f\t", p->nota);
        }
        p = p->proximo;
    }
    printf("\n");
}