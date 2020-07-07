#include <bits/stdc++.h>
#define Max 10

using namespace std;
int menu()
{
    int op;
    cout << "\n_______________________________________________________\n";
    cout << "\tMenu";
    cout << "\n_______________________________________________________\n";
    cout << "1 -> Cadastrar\n";
    cout << "2 -> Retirar um produto\n";
    cout << "3 -> Listar produtos\n";
    cout << "4 -> Digitar taxa de desconto para todos os produtos\n";
    cout << "5 -> Buscar produto com maior preco\n";
    cout << "6 -> Alterar preco de um produto";
    cout << "\n_______________________________________________________\n";
    cout << "7 -> Sair";
    cout << "\n_______________________________________________________\n";
    cout << "Digite uma opcao: ";
    scanf("%d", &op);
    return op;
}
///////////////////////////////////
struct lista
{
    int cod, quant;
    double preco;
    struct lista *ant;
    struct lista *prox;
};

typedef struct lista noptr;

///////////////////////////////////
void insere_lista(noptr **inifunc, int codigo, double pre, int quantidade);
void remove_lista(noptr **inifunc);
void lista_todos(noptr *inifunc);
void taxa_desconto(noptr **inifunc);
void buscar_maior_preco(noptr *inifunc);
void alterar_preco_produto(noptr **inifunc);
noptr *cria_novo(int codigo, double pre, int quantidade);
///////////////////////////////////

int main()
{
    int cod, quant;
    double preco;

    noptr *inicio = NULL;

    int op;

    do
    {
        op = menu();
        if (op == 1)
        {
            cout << "\nDigite o codigo do produto: ";
            cin >> cod;

            cout << "\nDigite o preco: ";
            scanf("%lf", &preco);

            cout << "\nDigite a quantidade estocada: ";
            cin >> quant;

            insere_lista(&inicio, cod, preco, quant);
            system("cls || clear");
        }
        else if (op == 2)
        {
            system("cls || clear");
            remove_lista(&inicio);
        }
        else if (op == 3)
        {
            system("cls || clear");
            lista_todos(inicio);
        }
        else if (op == 4)
        {
            system("cls || clear");
            taxa_desconto(&inicio);
        }
        else if (op == 5)
        {
            system("cls || clear");
            buscar_maior_preco(inicio);
        }
        else if (op == 6)
        {
            system("cls || clear");
            alterar_preco_produto(&inicio);
        }
    } while (op != 7);
}

void insere_lista(noptr **inifunc, int codigo, double pre, int quantidade)
{
    if (*inifunc == NULL)
    {
        *inifunc = cria_novo(codigo, pre, quantidade);
    }
    else
    {
        noptr *p = *inifunc, *novo;
        while (p->prox && p->cod < codigo)
        {
            p = p->prox;
        }
        if (p->cod != codigo)
        {
            novo = cria_novo(codigo, pre, quantidade);
            if (p == *inifunc && p->cod > codigo) //o cod eh menor q todos
            {
                p->ant = novo;
                novo->prox = p;
                *inifunc = novo;
            }
            else if (!p->prox && p->cod < codigo) //o cod eh maior que todos da lista
            {
                p->prox = novo;
                novo->ant = p;
            }
            else //o cod vai entrar no meio da lista
            {
                novo->ant = p->ant;
                novo->prox = p;
                p->ant = novo;
                novo->ant->prox = novo;
            }
        }
        else
        {
            p->quant += quantidade;
        }
        cout << "\n";
    }
}

void remove_lista(noptr **inifunc)
{
    noptr *p;
    p = *inifunc;
    if (*inifunc == NULL)
    {
        printf("\nLista Vazia!!!");
    }
    else
    {
        int cod1;
        cout << "_______________________________________________________\n";
        cout << "Digite o codigo do produto a ser removido: ";
        cin >> cod1;
        cout << "_______________________________________________________\n";

        while (p && p->cod != cod1)
        {
            p = p->prox;
        }
        if (p)
        {
            if (p->quant > 1)
            {
                p->quant--;
                cout << "\tRemovido!!\n";
                cout << "\n_________________________________\n";
                cout << "Produto atualizado: ";
                cout << "\n_________________________________\n";
                printf("\nCodigo: %d", p->cod);
                printf("\nPreco: %.2lf", p->preco);
                printf("\nQuantidade: %d", p->quant);
                cout << "\n_________________________________\n";
            }
            else
            {
                cout << "\tRemovido!!\n";
                cout << "\n_________________________________\n";
                cout << "Produto atualizado: ";
                cout << "\n_________________________________\n";
                printf("\nCodigo: %d", p->cod);
                printf("\nPreco: %.2lf", p->preco);
                printf("\nQuantidade: %d", --(p->quant));
                cout << "\n_________________________________\n";
                if (!p->ant && !p->prox)
                {
                    *inifunc = NULL;
                }
                else if (!p->ant)
                {
                    *inifunc = p->prox;
                    p->prox->ant = NULL;
                }
                else if (!p->prox)
                {
                    p->ant->prox = NULL;
                }
                else
                {
                    p->prox->ant = p->ant;
                    p->ant->prox = p->prox;
                }
                free(p);
            }
        }
        else
        {
            cout << "\nNao possui esse produto no cadastro!!\n";
        }
    }
}

void lista_todos(noptr *inifunc)
{
    if (inifunc == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }

    noptr *p;
    p = inifunc;
    cout << "\n_________________________________\n";
    cout << "\tProdutos:";
    cout << "\n_________________________________\n";

    while (p)
    {
        printf("\nCodigo: %d\n", p->cod);
        printf("Preco: %.2lf\n", p->preco);
        printf("Quantidade: %d\n", p->quant);
        cout << "\n_________________________________\n";
        p = p->prox;
    }
}

void taxa_desconto(noptr **inifunc)
{
    noptr *p;
    double desconto;
    cout << "_______________________________________________________\n";
    cout << "Digite o desconto em %, exemplos: 10; 20...\nDesconto: ";
    scanf("%lf", &desconto);
    cout << "_______________________________________________________\n";
    p = *inifunc;
    while (p)
    {
        p->preco = p->preco - (p->preco * (desconto / 100));
        p = p->prox;
    }
    return;
}

void buscar_maior_preco(noptr *inifunc)
{
    noptr *p;
    double maior = 0;
    p = inifunc;
    while (p)
    {
        if (p->preco > maior)
            maior = p->preco;

        p = p->prox;
    }
    p = inifunc;
    cout << "\n_________________________________\n";
    cout << "\tProduto(s) com maior preco:";
    cout << "\n_________________________________\n";
    while (p)
    {
        if (p->preco == maior)
        {

            cout << "\n_________________________________\n";
            printf("\nCodigo: %d\n", p->cod);
            printf("Preco: %.2lf\n", p->preco);
            printf("Quantidade: %d\n", p->quant);
            cout << "\n_________________________________\n";
        }
        p = p->prox;
    }
}

void alterar_preco_produto(noptr **inifunc)
{
    noptr *p;
    int cod1;
    double novoPreco;

    cout << "_______________________________________________________\n";
    cout << "Digite o codigo do produto para alterar o seu valor: ";
    cin >> cod1;
    cout << "\nDigite o novo preco do produto: ";
    scanf("%lf", &novoPreco);
    cout << "_______________________________________________________\n";

    p = *inifunc;
    while (p)
    {
        if (p->cod == cod1)
        {
            p->preco = novoPreco;
            cout << "\tProduto com preco alterado:\n";
            cout << "\n_________________________________\n";
            printf("\nCodigo: %d", p->cod);
            printf("\nPreco: %.2lf", p->preco);
            printf("\nQuantidade: %d", p->quant);
            cout << "\n_________________________________\n";
            break;
        }
        p = p->prox;
    }
}

noptr *cria_novo(int codigo, double pre, int quantidade)
{
    noptr *novo;
    novo = (struct lista *)malloc(sizeof(noptr));
    if (!novo)
    {
        printf("\nSem Memoria!!!");
        exit(0);
    }
    novo->cod = codigo;
    novo->preco = pre;
    novo->quant = quantidade;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}
