/*
03 – Faça um programa que cadastre produtos. Para cada produto devem ser cadastrados código do produto,
preço e quantidade estocada. 
Os dados devem ser armazenados em uma lista duplamente encadeada e ordenada pelo código. 
Posteriormente, crie uma função que mostra o código e o preço do produto com maior preço.
Mostre todos os produtos que foram cadastrados. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista9-ex3-online.h"
int main()
{

    int op;
    int cod, qtd;
    float preco;

    celula *inicio;
    inicio = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o codigo do produto\n");
            scanf("%d", &cod);
            printf("Digite a quantidade desse produto\n");
            scanf("%d", &qtd);
            printf("Digite o preco desse produto\n");
            scanf("%f", &preco);
            insere_lista(&inicio, cod, qtd, preco);
            break;
        case 2:
            lista_todos(inicio);
            break;
        case 3:
            lista_produto_caro(inicio);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        }
    } while (op != 0);

    return 0;
}