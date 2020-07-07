#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista9-ex2-online.h"
int main()
{

    int op;
    float nota;
    char nome[50];

    celula *inicio;
    inicio = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o nome do aluno\n");
            scanf("%s", nome);
            printf("Digite a nota desse aluno\n");
            scanf("%f", &nota);
            insere_lista(&inicio, nome, nota);
            break;
        case 2:
            lista_todos(inicio);
            break;
        case 3:
            lista_todos_aprovados(inicio);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        }
    } while (op != 0);

    return 0;
}
