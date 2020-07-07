/*
01 – Faça uma função que receba uma lista duplamente encadeada e envie para o programa principal
uma segunda lista 
com os valores positivos da primeira lista 
e uma terceira lista com os elementos negativos da primeira lista. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista9-ex1-online.h"
int main()
{
    int op, valor;

    celula *inicio;
    inicio = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o valor para lista: ");
            scanf("%d", &valor);
            insere_lista(&inicio, valor);
            break;

        case 2:
            lista_todos(inicio);
            break;
        case 3:
            lista_positivos(inicio);
            break;
        case 4:
            lista_negativos(inicio);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        }
    } while (op != 0);

    return 0;
}