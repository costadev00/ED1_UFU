//struct de dados
typedef struct no
{
    int codigo;
    char nome[100];
    char categoria[100];
    int numero_pag;
    char resumo[500];
    float preco;
    int estoque;
    struct no *proximo;
    struct no *anterior;
} no;

//prototipos
void addLivro(no **inicio);
void initLista(no **inicio);
void mostraLivros(no *inicio);
void efetuarVenda(no **inicio);
void consultaNomeLivro(no **inicio);
void mostraRelatorios_Vendas();
int validaEntrada(int *valorRecebido);
no *cria_novo(int codigo, char nome[], char categoria[], int numero_pag, char resumo[], double preco, int estoque);
//

//funcao de inicializar a lista
void initLista(no **inicio)
{
    (*inicio) = NULL;
}

no *cria_novo(int codigo, char nome[], char categoria[], int numero_pag, char resumo[], double preco, int estoque)
{
    no *novo;
    novo = (struct no *)malloc(sizeof(no));
    if (!novo)
    {
        printf("\nSem Memoria!!!");
        exit(0);
    }
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    strcpy(novo->categoria, categoria);
    novo->numero_pag = numero_pag;
    strcpy(novo->resumo, resumo);
    novo->preco = preco;
    novo->estoque = estoque;

    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

//funcao de cadastrar novo livro
void addLivro(no **inicio)
{
    //declaracoes
    int codigo;
    char nome[100];
    char categoria[100];
    int numero_pag;
    char resumo[500];
    float preco;
    int estoque;

    printf("\t ---- Cadastrar um novo livro ---- \t \n");
    printf("Digite o codigo desse livro:\n");
    scanf("%d", &codigo);

    printf("Digite o nome desse livro:\n");
    setbuf(stdin, NULL);
    fgets(nome, 100, stdin);
    //fread(&nome, sizeof(char), 1, stdin);

    printf("Digite a categoria desse livro:\n");
    // fread(&categoria, sizeof(char), 1, stdin);
    setbuf(stdin, NULL);
    fgets(categoria, 100, stdin);

    printf("Digite o número de páginas que esse livro possui:\n");
    scanf("%d", &numero_pag);

    printf("Escreva um breve resumo desse livro:\n");
    setbuf(stdin, NULL);
    fgets(resumo, 500, stdin);

    printf("Digite o preço desse livro:\n");
    scanf("%f", &preco);

    printf("Digite a quantidade de unidades desse livro:\n");
    scanf("%d", &estoque);

    if (*inicio == NULL)
    {
        *inicio = cria_novo(codigo, nome, categoria, numero_pag, resumo, preco, estoque);
    }
    else
    {
        no *p = *inicio, *novo;

        novo = cria_novo(codigo, nome, categoria, numero_pag, resumo, preco, estoque);

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
    system("cls || clear");
    printf("Livro cadastrado com sucesso!\n");
    printf("------------------\n");
}

void mostraLivros(no *inicio)
{
    //declaracoes
    no *p;
    if (inicio == NULL)
    {
        printf("Não há livros presentes na livraria\n");
    }
    else
    {
        p = inicio;

        while (p)
        {
            printf("%s\n", p->nome);
            p = p->proximo;
        }
    }
}
// faz a remoção de um elemento desejado, e diminui a sua variável estoque também
void efetuarVenda(no **inicio)
{
    int uni = 0;
    no *p;
    int res = 1;
    char nome[100];

    printf("Qual o nome do livro ?\n");
    getchar();
    fgets(nome, 100, stdin);
    p = *inicio;
    // printf("fodase 1\n");
    while (p && res != 0)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            res = 0;
            printf("Livro encontrado!\n");
            // printf("fodase3\n");
            if (p->estoque <= 0)
            {
                printf("Estoque indisponível!\n");
            }
            else
            {
                printf("O estoque dessa unidade é de: %d\n", p->estoque);
                printf("Quantas unidades deseja vender\n");
                scanf("%d", &uni);
                while (uni > p->estoque)
                {
                    printf("Não é possível vender essa quantidade pois o estoque é somente de %d unidades\n", p->estoque);
                    printf("Digite quantas unidades deseja vender:\n");
                    scanf("%d", &uni);
                }
                p->estoque -= uni;
                system("cls || clear");
                printf("Venda efetuada com sucesso!\n");
            }
        }
        else
        {
            p = p->proximo;
        }
    }
    if (res != 0)
    {

        printf("Livro não encontrado!\n");
    }
    //gera o relatorio das vendas
    FILE *file;
    file = fopen("RELATORIO.txt", "a+");
    fprintf(file, "CODIGO: %d\t NOME: %s\t QUANTIDADE VENDIDA: %d livros\t \n\n", p->codigo, p->nome, uni);
    fclose(file);
}
//faz consulta se algum livro exite na lista
void consultaNomeLivro(no **inicio)
{
    int res = 1;
    char nome[100];
    no *p;
    printf("Qual o nome do livro ?\n");
    getchar();
    fgets(nome, 100, stdin);
    p = *inicio;
    while (p)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            res = 0;
            printf("Livro encontrado!\n");
            printf("Contém %d unidade(s) desse livro\n", p->estoque);
        }
        p = p->proximo;
    }
    if (res != 0)
    {

        printf("Livro não encontrado!\n");
    }
}
//chama o arquivo txt com o relatorio
void mostraRelatorio_Vendas()
{
    printf("Abrindo relatório...\n");
}

//Opção para Validação da Entrada
int validaEntrada(int *valorRecebido)
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