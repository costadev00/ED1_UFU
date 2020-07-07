#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct celulaLista
{
    int cod_produto, qtd_produto;
    float preco;
    struct celulaLista *anterior;
    struct celulaLista *proximo;
} celula;

int menu()
{

    int op;

    printf("\nMenu\n\n");
    printf("1 -Cadastrar um produto\n");
    printf("2 -Listar todos os produtos\n");
    printf("3 -Listar produto mais caro\n");
    printf("0 -Sair\n");
    printf("Digite uma opcao:\n");
    scanf("%d", &op);
    return op;
}

void insere_lista(celula **inicio, int cod, int qtd, float preco);
void remove_lista(celula **inicio);
void lista_todos(celula *inicio);
void lista_produto_caro(celula *inicio);

void insere_lista(celula **inicio, int cod, int qtd, float preco)
{
    celula *p;
    p = (struct celulaLista *)malloc(sizeof(celula));
    if (!p)
    {
        printf("\nSem Memoria!!!");
    }

    p->cod_produto = cod;
    p->qtd_produto = qtd;
    p->preco = preco;
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
        printf("\n Não há produto cadastrado!!!");
        return;
    }
    celula *p;
    p = inicio;
    while (p)
    {
        printf("\n--- Produto %d ---\n", p->cod_produto);
        printf("Cod: : %d\n", p->cod_produto);
        printf("Quantidade: : %d\n", p->qtd_produto);
        printf("Preço: : %.2f\n", p->preco);
        p = p->proximo;
    }
    printf("\n");
}

void lista_produto_caro(celula *inicio)
{
    float maior;
    int cod;
    if (inicio == NULL)
    {
        printf("\nNão há produto cadastrado!!!");
        return;
    }
    celula *p;
    p = inicio;
    maior = p->preco;
    cod = p->cod_produto;
    while (p)
    {
        if (p->preco > maior)
        {
            maior = p->preco;
            cod = p->cod_produto;
        }
        p = p->proximo;
    }
    printf("O produto com maior preço: é o %d : %.2f\n", cod, maior);
}