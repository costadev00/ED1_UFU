#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datanascimento
{
    int dia;
    int mes;
    int ano;

} datanascimento;

typedef struct enderecocliente
{
    char rua[40];
    int numero;
    char cidade[40];
    char estado[40];

} enderecocliente;

typedef struct cliente
{
    char cpf[12];
    char nome[100];
    char telefone[12];
    int idade;
    struct enderecocliente endereco;
    struct datanascimento data;
    struct cliente *esq;
    struct cliente *dir;

} cliente;

cliente *insere(cliente *root, cliente *r, char cpf[12], char nome[100], char telefone[12], char rua[40], int numero, char cidade[40], char estado[40], int dia, int mes, int ano)
{

    if (r == NULL)
    {
        r = (cliente *)malloc(sizeof(cliente));
        if (r == NULL)
        {
            system("cls");
            printf("Memoria Insufuciente!!!");
            getch();
        }
        else
        {
            r->esq = NULL;
            r->dir = NULL;
            strcpy(r->nome, nome);
            strcpy(r->endereco.rua, rua);
            strcpy(r->endereco.cidade, cidade);
            strcpy(r->endereco.estado, estado);
            strcpy(r->cpf, cpf);
            strcpy(r->telefone, telefone);
            r->endereco.numero = numero;
            r->data.dia = dia;
            r->data.mes = mes;
            r->data.ano = ano;

            if (r->data.mes > 10)
            {
                r->idade = 2020 - r->data.ano - 1;
            }
            else
            {
                r->idade = 2020 - r->data.ano;
            }

            if (root == NULL)
            {
                return r;
            }
            if (strcmp(r->cpf, root->cpf) == 0)
            {
                system("cls");
                printf("\nNao foi possivel cadastrar o cliente. CPF ja cadastrado anteriormente.\n\n");
                getch();
            }
            else if (strcmp(r->cpf, root->cpf) < 0)
            {
                root->esq = r;
            }
            else
            {
                root->dir = r;
            }
            return r;
        }
    }
    if (strcmp(cpf, r->cpf) < 0)
    {
        insere(r, r->esq, cpf, nome, telefone, rua, numero, cidade, estado, dia, mes, ano);
    }
    else
    {
        insere(r, r->dir, cpf, nome, telefone, rua, numero, cidade, estado, dia, mes, ano);
    }
    return r;
}

void mostrar(cliente *root)
{
    if (root == NULL)
    {
        return;
    }
    mostrar(root->esq);
    printf("\n%s\n", root->cpf);
    printf("%s\n\n", root->nome);
    mostrar(root->dir);
}

void consulta(cliente *root, char cpf[])
{
    if (root != NULL)
    {
        if (strcmp(root->cpf, cpf) > 0)
        {
            consulta((root)->esq, cpf);
        }
        else
        {
            if (strcmp(root->cpf, cpf) < 0)
            {
                consulta((root)->dir, cpf);
            }
            else
            {
                if (strcmp(root->cpf, cpf) == 0)
                {
                    system("cls");
                    printf("\ncliente pesquisado:\n\ncpf: %s\nnome: %s\ntelefone: %s\nendereco:\nrua: %s\nnumero: %d\ncidade: %s\nestado: %s\ndata de nascimento: %d/%d/%d\n\n", root->cpf, root->nome, root->telefone, root->endereco.rua, root->endereco.numero, root->endereco.cidade, root->endereco.estado, root->data.dia, root->data.mes, root->data.ano);
                    getch();
                }
            }
        }
    }
    else
    {
        system("cls");
        printf("\nNao ha esse cliente\n\n");
        getch();
    }
}

int quantidadetotal(cliente *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + quantidadetotal(root->esq) + quantidadetotal(root->dir);
    }
}

int quantidadeIdade(cliente *root, int idade, int cont)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->idade >= idade)
        {
            return 1 + quantidadeIdade(root->esq, idade, cont) + quantidadeIdade(root->dir, idade, cont);
        }
        else
        {
            return 0 + quantidadeIdade(root->esq, idade, cont) + quantidadeIdade(root->dir, idade, cont);
        }
    }
}

void alterar(cliente **root, char cpf[])
{
    if ((*root) != NULL)
    {
        if (strcasecmp((*root)->cpf, cpf) > 0)
        {
            alterar(&(*root)->esq, cpf);
        }
        else
        {
            if (strcasecmp((*root)->cpf, cpf) < 0)
            {
                alterar(&(*root)->dir, cpf);
            }
            else
            {
                if (strcmp((*root)->cpf, cpf) == 0)
                {
                    int a, numero;
                    char rua[40], cidade[40], estado[40], nome[100], telefone[12];
                    system("cls");
                    printf("\nDigite o numero de acordo com o dado a ser alterado:\n\n");
                    printf("1 - nome\n");
                    printf("2 - telefone\n");
                    printf("3 - endereco\n");
                    scanf("%d", &a);
                    switch (a)
                    {
                    case 1:
                        system("cls");
                        printf("Digite o novo nome do cliente:\n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", &nome);
                        strcpy((*root)->nome, nome);
                        break;
                    case 2:
                        system("cls");
                        printf("Digite o novo telefone do cliente:\n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", &telefone);
                        strcpy((*root)->telefone, telefone);
                        break;
                    case 3:
                        system("cls");
                        printf("Digite o novo endereco do cliente:\n");
                        printf("Rua:\n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", &rua);
                        strcpy((*root)->endereco.rua, rua);
                        printf("Numero:\n");
                        scanf("%d", &numero);
                        (*root)->endereco.numero = numero;
                        printf("Cidade:\n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", &cidade);
                        strcpy((*root)->endereco.cidade, cidade);
                        printf("Estado:\n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", &estado);
                        strcpy((*root)->endereco.estado, estado);
                        break;
                    default:
                        system("cls");
                        printf("Opcao invalida\n");
                        getch();
                    }
                }
            }
        }
    }
    else
    {
        system("cls");
        printf("\nNao ha esse cliente\n\n");
        getch();
    }
}

cliente *MaiorDireita(cliente **root)
{
    if ((*root)->dir != NULL)
    {
        return MaiorDireita(&(*root)->dir);
    }
    else
    {
        cliente *aux = *root;

        if ((*root)->esq != NULL) // se nao houver essa verificacao, esse nao vai perder todos os seus filhos da esquerda!
        {
            *root = (*root)->esq;
        }
        else
        {
            *root = NULL;
            return aux;
        }
    }
}

void deletar(cliente **root, char cpf[])
{
    if (*root == NULL) // esta verificacao serve para caso o cpf nao exista na arvore.
    {
        printf("cliente nao existe!");
        getch();
        return;
    }
    if (strcmp(cpf, (*root)->cpf) < 0)
        deletar(&(*root)->esq, cpf);
    else if (strcmp(cpf, (*root)->cpf) > 0)
        deletar(&(*root)->dir, cpf);
    else // se nao eh menor nem maior, logo, eh o cpf que estou procurando! :)
    {
        cliente *pAux = *root;
        if (((*root)->esq == NULL) && ((*root)->dir == NULL)) // se nao houver filhos...
        {
            free(pAux);
            (*root) = NULL;
        }
        else // so tem o filho da direita
        {
            if ((*root)->esq == NULL)
            {
                (*root) = (*root)->dir;
                pAux->dir = NULL;
                free(pAux);
                pAux = NULL;
            }
            else //so tem filho da esquerda
            {
                if ((*root)->dir == NULL)
                {
                    (*root) = (*root)->esq;
                    pAux->esq = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else //Escolhi fazer o maior filho direito da subarvore esquerda.
                {
                    pAux = MaiorDireita(&(*root)->esq);
                    pAux->esq = (*root)->esq;
                    pAux->dir = (*root)->dir;
                    (*root)->esq = (*root)->dir = NULL;
                    free((*root));
                    (*root) = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}

int main()
{

    int a, total, cont, dia, mes, ano, numero, idade, valor;
    char rua[40], cidade[40], estado[40], nome[100], cpf[12], telefone[12];

    cliente *raiz;
    raiz = NULL;

    do
    {
        system("cls");
        printf("\nDigite o numero de acordo com a opcao desejada:\n\n");
        printf("1 - incluir cliente\n");
        printf("2 - alterar dados de um cliente\n");
        printf("3 - consultar dados de um cliente\n");
        printf("4 - deletar cliente\n");
        printf("5 - mostrar todos os clientes cadastrados\n");
        printf("6 - mostrar a quantidade de clientes cadastrados\n");
        printf("7 - quantos clientes possuem idade acima de uma idade definida\n");
        printf("0 - Sair\n\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            printf("Digite o nome do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &nome);
            printf("Digite o telefone:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &telefone);
            printf("Digite o endereco:\n");
            printf("Rua:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &rua);
            printf("Numero:\n");
            scanf("%d", &numero);
            printf("Cidade:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cidade);
            printf("Estado:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &estado);
            printf("Digite a data de nascimento:\n");
            printf("Dia:\n");
            scanf("%d", &dia);
            printf("Mes(numero):\n");
            scanf("%d", &mes);
            printf("Ano:\n");
            scanf("%d", &ano);
            if (raiz == NULL)
            {
                raiz = insere(raiz, raiz, cpf, nome, telefone, rua, numero, cidade, estado, dia, mes, ano);
            }
            else
            {
                insere(raiz, raiz, cpf, nome, telefone, rua, numero, cidade, estado, dia, mes, ano);
            }

            break;
        case 2:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            alterar(&raiz, cpf);
            break;
        case 3:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            consulta(raiz, cpf);
            break;
        case 4:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            deletar(&raiz, cpf);
            break;
        case 5:
            system("cls");
            if (raiz == NULL)
            {
                printf("\nNenhum cliente foi cadastrado!\n\n");
            }
            else
            {
                mostrar(raiz);
            }
            getch();
            break;
        case 6:
            total = quantidadetotal(raiz);
            system("cls");
            printf("\nHa %d clientes cadastrados\n", total);
            getch();
            break;
        case 7:
            system("cls");
            printf("Digite a idade:\n");
            scanf("%d", &idade);
            cont = 0;
            total = quantidadeIdade(raiz, idade, cont);
            printf("\nHa %d clientes cadastrados com idade acima de %d anos\n", total, idade);
            getch();
            break;
        case 0:

            break;
        default:
            system("cls");
            printf("Opcao invalida\n");
            getch();
        }
    } while (a != 0);
    return 0;
}
