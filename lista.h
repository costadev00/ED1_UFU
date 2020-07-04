typedef struct celulaLista
{
    int informacao;
    struct celulaLista *proximo;
} celula;
//prototipos
void initLista(celula **pRecebido);
void insertLista(celula **pRecebido);
void buscaListaSimples(celula **pRecebido);
void removeElementoListaSimples(celula **pRecebido);
void mostraSoma(celula **inicio);
int leValor(int *valorRecebido);

// *Inicialização da Lista Encadeada
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

void mostraSoma(celula **inicio)
{
    // Declarações
    int soma = 0;
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
            soma = soma + p->informacao;
            p = p->proximo;
        }
        printf("Soma : %d\n", soma);
    }
}

void mostrarInicio(celula **inicio)
{ // Declarações
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
        printf("Valor : %d\n", p->informacao);
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
    while ((*valorRecebido > 5) || (*valorRecebido < 0))
    {
        printf("Opcao Invalida. Informe novamente : \n");
        scanf("%d", &(*valorRecebido));
    }
    return (*valorRecebido);
}
