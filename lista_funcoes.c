/*
Desenvolva um programa que tenha as seguintes estruturas:
Fila, Fila Circular, Pilha.
Utilize lista duplamente encadeada, que contenham as funções de:
Inserir, Remover, Mostrar.
...
codigo idealizado com a ajuda de Rafael Cosme
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dados;
    struct no *prox, *ant;

} noptr;

void menu(int *op, int *op1, int *op2, int *op3)
{

    printf("\t1. Inserir.\n");
    printf("\t2. Remover.\n");
    printf("\t3. Listar.\n");
    printf("\t0. Encerrar programa.\n");

    scanf("%d", &(*op));

    if ((*op) == 1)
    {

        system("cls");

        printf("\t1. Inserir em Fila.\n");
        printf("\t2. Inserir em Fila Circular.\n");
        printf("\t3. Inserir em Pilha.\n");

        scanf("%d", &(*op1));
    }
    else if ((*op) == 2)
    {

        system("cls");

        printf("\t1. Remover em Fila.\n");
        printf("\t2. Remover em Fila Circular.\n");
        printf("\t3. Remover em Pilha.\n");

        scanf("%d", &(*op2));
    }
    else if ((*op) == 3)
    {

        system("cls");

        printf("\t1. Listar Fila\n");
        printf("\t2. Listar Fila Circular\n");
        printf("\t3. Listar Pilha\n");

        scanf("%d", &(*op3));
    }
}

void insere_final(noptr **inicio, noptr *nova, int x)
{
    nova = (struct no *)malloc(sizeof(noptr));

    if (!nova)
    {
        printf("Sem memoria!\n\n");
        return;
    }
    else
    {

        noptr *p;
        p = (*inicio);

        nova->dados = x;
        printf("Valor adicionado: %d\n", nova->dados);

        if ((*inicio) == NULL) //Adicionando em lista vazia
        {
            (*inicio) = nova;
            nova->ant = NULL;
            nova->prox = NULL;
        }
        else
        {
            while (p->prox != NULL)
                p = p->prox;

            p->prox = nova;
            nova->ant = p;
            nova->prox = NULL;
        }
    }
}

void insere_inicio(noptr **inicio, noptr *nova, int x)
{
    nova = (struct no *)malloc(sizeof(noptr));

    if (!nova)
    {
        printf("Sem memoria!\n\n");
        return;
    }
    else
    {

        noptr *p;
        p = (*inicio);

        nova->dados = x;
        printf("Valor adicionado: %d\n", nova->dados);

        if ((*inicio) == NULL) //Adicionando em lista vazia
        {
            (*inicio) = nova;
            nova->ant = NULL;
            nova->prox = NULL;
        }
        else
        {
            (*inicio) = nova;
            nova->ant = NULL;
            nova->prox = p;
        }
    }
}

void insere_fila_circular(noptr **inicio, noptr *nova, noptr **ultimo, int x)
{
    nova = (struct no *)malloc(sizeof(noptr));

    if (!nova)
    {
        printf("Sem memoria!\n\n");
        return;
    }
    else
    {

        noptr *p;
        p = (*inicio);

        nova->dados = x;
        printf("Valor adicionado: %d\n", nova->dados);

        if ((*inicio) == NULL) //Adicionando em lista vazia
        {
            (*inicio) = nova;
            nova->ant = NULL;
            nova->prox = (*inicio);
            (*ultimo) = nova;
        }
        else
        {
            while (p->prox != (*inicio))
                p = p->prox;

            nova->prox = (*inicio);
            p->prox = nova;
            nova->ant = p;
            (*ultimo) = nova;
        }
    }
}

void remove_fila_circular(noptr **inicio, noptr *ultimo)
{
    if ((*inicio) == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }
    else
    {
        noptr *p;
        p = (*inicio);

        printf("Removendo: %d\n", p->dados);

        if (p == ultimo)
        {
            (*inicio) = NULL;
            free(p);
        }
        else
        {
            (*inicio) = p->prox;
            p->prox->ant = NULL;
            free(p);
        }
    }
}

void remove_inicio(noptr **inicio)
{
    if ((*inicio) == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }
    else
    {
        noptr *p;
        p = (*inicio);

        printf("Removendo: %d\n", p->dados);

        if (p->prox == NULL)
        {
            (*inicio) = NULL;
            free(p);
        }
        else
        {
            (*inicio) = p->prox;
            p->prox->ant = NULL;

            free(p);
        }
    }
}

/*void remove_final(noptr **inicio)
{
    if((*inicio)==NULL){
        printf("Lista Vazia!\n");
        return;
    }
    else{
        noptr *p;
        p=(*inicio);

        if(p->prox==NULL&&p->ant==NULL){
            printf("Removendo: %d\n", p->dados);
            (*inicio)=NULL;
            free(p);
        }
        else{
            while(p->prox!=NULL)
                p=p->prox;

            printf("Removendo: %d\n", p->dados);

            p->ant->prox=NULL;
            free(p);
        }
    }
}*/

void lista_todos(noptr *inicio, noptr *ultimo, int flag)
{
    if (inicio == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }
    else
    {
        noptr *p;

        p = inicio;

        if (flag == 1)
        {
            while (p != ultimo)
            {
                printf("Dados: %d\n", p->dados);
                p = p->prox;
            }
            printf("Dados: %d\n", p->dados);
            printf("\nUltimo: %d\n", ultimo->dados);
        }
        else if (inicio != NULL)
        {
            while (p != NULL)
            {
                printf("Dados: %d\n", p->dados);
                p = p->prox;
            }
        }
    }
    printf("\n");
}

int main()
{
    noptr *inicio1, *inicio2, *inicio3, *ultimo;
    noptr *info;

    inicio1 = NULL, inicio2 = NULL, inicio3 = NULL, ultimo = NULL;

    int x = 0;
    int op = 0;
    int flag = 0;

    do
    {

        int op1 = 0, op2 = 0, op3 = 0;

        menu(&op, &op1, &op2, &op3);

        //Verificando em qual lista duplamente encadeada devo adicionar elemento

        if (op1 == 1)
        { //Adiciono em fila
            printf("Digite valor a ser adicionado:\n");
            scanf("%d", &x);
            insere_final(&inicio1, info, x);

            system("pause");
            system("cls");
        }
        else if (op1 == 2)
        { //Adiciono em fila circular
            printf("Digite valor a ser adicionado:\n");
            scanf("%d", &x);
            insere_fila_circular(&inicio2, info, &ultimo, x);

            system("pause");
            system("cls");
        }
        else if (op1 == 3)
        { //Adiciono em pilha
            printf("Digite valor a ser adicionado:\n");
            scanf("%d", &x);
            insere_inicio(&inicio3, info, x);

            system("pause");
            system("cls");
        }

        //Verificando em qual lista duplamente encadeada devo remover elemento

        if (op2 == 1)
        { //Removo em fila
            remove_inicio(&inicio1);

            system("pause");
            system("cls");
        }
        else if (op2 == 2)
        { //Removo em fila-circular
            remove_fila_circular(&inicio2, ultimo);

            system("pause");
            system("cls");
        }
        else if (op2 == 3)
        { //Removo em pilha
            remove_inicio(&inicio3);

            system("pause");
            system("cls");
        }

        //Verificando qual lista duplamente encadeada devo listar:

        if (op3 == 1)
        { //Lista fila
            printf("\n");
            flag = 0;

            if (inicio1 != NULL)
                printf("\tFila:\n");
            lista_todos(inicio1, ultimo, flag);

            system("pause");
            system("cls");
        }
        else if (op3 == 2)
        { //Lista fila circular
            printf("\n");
            flag = 1;

            if (inicio2 != NULL)
                printf("\tFila-Circular:\n");
            lista_todos(inicio2, ultimo, flag);

            system("pause");
            system("cls");
        }
        else if (op3 == 3)
        { //Lista pilha
            printf("\n");
            flag = 0;

            if (inicio3 != NULL)
                printf("\tPilha:\n");
            lista_todos(inicio3, ultimo, flag);

            system("pause");
            system("cls");
        }

        else if (op == 0)
            printf("\nEncerrando programa...\n");

    } while (op != 0);

    return 0;
}