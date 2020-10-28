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
    struct cliente *anterior;
    struct cliente *proximo;

} cliente;

void insere(cliente **inicio, char cpf[12], char nome[100], char telefone[12], char rua[40], int numero, char cidade[40], char estado[40], int dia, int mes, int ano)
{
    cliente *p, *aa;
    aa = *inicio;
    p = (struct cliente *)malloc(sizeof(cliente));
    if (!p)
    {
        system("cls");
        printf("\nSem memoria!\n\n");
        getch();
    }
    else
    {
        strcpy(p->nome, nome);
        strcpy(p->endereco.rua, rua);
        strcpy(p->endereco.cidade, cidade);
        strcpy(p->endereco.estado, estado);
        strcpy(p->cpf, cpf);
        strcpy(p->telefone, telefone);
        p->endereco.numero = numero;
        p->data.dia = dia;
        p->data.mes = mes;
        p->data.ano = ano;

        if (p->data.mes > 10)
        {
            p->idade = 2020 - p->data.ano - 1;
        }
        else
        {
            p->idade = 2020 - p->data.ano;
        }

        if (aa == NULL)
        {
            p->proximo = NULL;
            p->anterior = NULL;
            *inicio = p;
        }
        else
        {
            while (strcmp(cpf, aa->cpf) > 0 && aa->proximo != NULL)
            {
                aa = aa->proximo;
            }
            if (strcmp(cpf, aa->cpf) == 0)
            {
                system("cls");
                printf("\nNao foi possivel cadastrar o cliente. CPF ja cadastrado anteriormente.\n\n");
                getch();
            }
            else if (strcmp(cpf, aa->cpf) < 0)
            {
                if (aa->anterior == NULL)
                {
                    p->proximo = aa;
                    p->anterior = NULL;
                    aa->anterior = p;
                    *inicio = p;
                }
                else
                {
                    p->proximo = aa;
                    p->anterior = aa->anterior;
                    aa->anterior->proximo = p;
                    aa->anterior = p;
                }
            }
            else
            {
                if (aa->proximo == NULL)
                {
                    p->proximo = NULL;
                    p->anterior = aa;
                    aa->proximo = p;
                }
            }
        }
    }
}

void mostrar(cliente *inicio)
{
    if (inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        cliente *p;
        p = inicio;
        system("cls");
        printf("\nLista de todos os clientes:\n\n");
        while (p)
        {
            printf("cpf: %s\nnome: %s\n\n", p->cpf, p->nome);
            p = p->proximo;
        }
        printf("\n");
        getch();
    }
}

void consulta(cliente *inicio, char cpf[])
{
    if (inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        cliente *p;
        p = inicio;
        while (p && strcmp(cpf, p->cpf) != 0)
        {
            p = p->proximo;
            if (p == NULL)
            {
                system("cls");
                printf("\nNao ha esse cliente\n\n");
                getch();
                break;
            }
        }
        if (p != NULL)
        {
            system("cls");
            printf("\ncliente pesquisado:\n\ncpf: %s\nnome: %s\ntelefone: %s\nendereco:\nrua: %s\nnumero: %d\ncidade: %s\nestado: %s\ndata de nascimento: %d/%d/%d\n\n", p->cpf, p->nome, p->telefone, p->endereco.rua, p->endereco.numero, p->endereco.cidade, p->endereco.estado, p->data.dia, p->data.mes, p->data.ano);
            getch();
        }
    }
}

void quantidadetotal(cliente *inicio)
{
    if (inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        int cont = 0;
        cliente *p;
        p = inicio;
        while (p)
        {
            cont++;
            p = p->proximo;
        }
        system("cls");
        printf("\nHa %d clientes cadastrados\n", cont);
        getch();
    }
}

void quantidadeIdade(cliente *inicio, int idade)
{
    if (inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        int cont = 0;
        cliente *p;
        p = inicio;
        while (p)
        {
            if (p->idade >= idade)
            {
                cont++;
            }
            p = p->proximo;
        }
        system("cls");
        printf("\nHa %d clientes cadastrados com idade acima de %d anos\n", cont, idade);
        getch();
    }
}

void alterar(cliente **inicio, char cpf[])
{
    if (inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        cliente *p;
        p = *inicio;
        while (p && strcmp(cpf, p->cpf) != 0)
        {
            p = p->proximo;
            if (p == NULL)
            {
                system("cls");
                printf("\nNao ha esse cliente\n\n");
                getch();
                break;
            }
        }
        if (p != NULL)
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
                strcpy(p->nome, nome);
                break;
            case 2:
                system("cls");
                printf("Digite o novo telefone do cliente:\n");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", &telefone);
                strcpy(p->telefone, telefone);
                break;
            case 3:
                system("cls");
                printf("Digite o novo endereco do cliente:\n");
                printf("Rua:\n");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", &rua);
                strcpy(p->endereco.rua, rua);
                printf("Numero:\n");
                scanf("%d", &numero);
                p->endereco.numero = numero;
                printf("Cidade:\n");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", &cidade);
                strcpy(p->endereco.cidade, cidade);
                printf("Estado:\n");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", &estado);
                strcpy(p->endereco.estado, estado);
                break;
            default:
                system("cls");
                printf("Opcao invalida\n");
                getch();
            }
        }
    }
}

void deletar(cliente **inicio, char cpf[])
{
    if (*inicio == NULL)
    {
        system("cls");
        printf("\nNenhum cliente foi cadastrado!\n\n");
        getch();
        return;
    }
    else
    {
        cliente *p;
        p = *inicio;
        while (p && strcmp(cpf, p->cpf) != 0)
        {
            p = p->proximo;
            if (p == NULL)
            {
                system("cls");
                printf("\nNao ha esse cliente\n\n");
                getch();
                break;
            }
        }
        if (p != NULL)
        {

            if (p->anterior == NULL && p->proximo == NULL)
            {
                *inicio = NULL;
            }
            else if (p->anterior == NULL)
            {
                p->proximo->anterior = NULL;
                *inicio = p->proximo;
            }
            else if (p->proximo == NULL)
            {
                p->anterior->proximo = NULL;
            }

            else
            {
                p->proximo->anterior = p->anterior;
                p->anterior->proximo = p->proximo;
            }
            system("cls");
            printf("\nO cliente foi deletado\n\n");
            getch();
            free(p);
        }
    }
}

int main()
{

    int a, dia, mes, ano, numero, idade;
    char rua[40], cidade[40], estado[40], nome[100], cpf[12], telefone[12];
    cliente *pessoa;
    pessoa = NULL;
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
            insere(&pessoa, cpf, nome, telefone, rua, numero, cidade, estado, dia, mes, ano);
            break;
        case 2:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            alterar(&pessoa, cpf);
            break;
        case 3:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            consulta(pessoa, cpf);
            break;
        case 4:
            system("cls");
            printf("Digite o cpf do cliente:\n");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", &cpf);
            deletar(&pessoa, cpf);
            break;
        case 5:
            mostrar(pessoa);
            break;
        case 6:
            quantidadetotal(pessoa);
            break;
        case 7:
            system("cls");
            printf("Digite a idade:\n");
            scanf("%d", &idade);
            quantidadeIdade(pessoa, idade);
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
