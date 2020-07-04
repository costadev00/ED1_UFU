#include <stdio.h>
#include <stdlib.h>

typedef struct celulaLista
{
    int informacao;
    struct celulaLista *proximo;
} celula;

void initLista(celula **pRecebido);
void insertLista(celula **pRecebido);
void buscaListaSimples(celula **pRecebido);
void removeElementoListaSimples(celula **pRecebido);
int leValor(int *valorRecebido);

int main()
{
    // Declarações
    celula *pLista;
    int opcao = 0;

    // Instruções
    pLista = (celula *)malloc(sizeof(struct celulaLista));
    initLista(&pLista);
    for (;;)
    {
        printf("\n1 - Inserir : ");
        printf("\n2 - Consultar: ");
        printf("\n3 - Remover");
        printf("\n4 - Sair\n");
        scanf("%d", &opcao);
        opcao = leValor(&opcao);
        switch (opcao)
        {
        case 1:
            insertLista(&pLista);
            break;
        case 2:
            buscaListaSimples(&pLista);
            break;
        case 3:
            // mostraSoma(&pLista);
            printf("vai tomar no cu\n");
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
/*
   Inicialização da Lista Encadeada
*/
void initLista(celula **inicio)
{
    (*inicio) = NULL;
}

/*
   Função para Inserção no Início
*/
void insertLista(celula **inicio)
{
    // Declarações
    celula *p;
    int valor;

    // Instruções
    printf("\nInforme um Valor a ser Inserido : ");
    scanf("%d", &valor);
    p = (celula *)malloc(sizeof(celula));

    p->informacao = valor;

    if (*inicio == NULL)
        p->proximo = NULL;
    else
        p->proximo = *inicio;

    *inicio = p;
}
/*
   Função para Percorrer Elementos
*/
void buscaListaSimples(celula **inicio)
{
    // Declarações
    celula *p;
    // Instruções
    if (*inicio == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        p = (celula *)malloc(sizeof(celula));
        p = *inicio;
        while (p)
        {
            printf("Valor : %d\n", p->informacao);
            p = p->proximo;
        }
    }
}
/*
   Remove Elemento da Cabeça
*/
void removeElementoListaSimples(celula **inicio)
{
    // Declarações
    celula *p;
    // Instruções
    if ((*inicio)->proximo == NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        p = (*inicio);
        printf("Número Removido: %d\n", p->informacao);
        (*inicio)->proximo = p->proximo;
        free(p);
    }
}
/*
   Opção para Validação da Entrada
*/
int leValor(int *valorRecebido)
{
    // Declarações
    // Instruções
    while ((*valorRecebido > 4) || (*valorRecebido < 1))
    {
        printf("Opcao Invalida. Informe novamente : \n");
        scanf("%d", &(*valorRecebido));
    }
    return (*valorRecebido);
}