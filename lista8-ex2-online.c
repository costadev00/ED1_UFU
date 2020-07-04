/*
02 – Faça um algoritmo que contenha as seguintes opções: 
1 - Inserir elemento na lista
2 - Retirar elemento da lista
3 - Mostrar o total da soma de todos os elementos 
4 - Mostrar todos os elementos da lista 0 - Sai

*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
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
        printf("\n2 - Remover: ");
        printf("\n3 - Mostrar Soma");
        printf("\n4 - Mostrar Lista");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);
        opcao = leValor(&opcao);
        switch (opcao)
        {
        case 1:
            insertLista(&pLista);
            break;
        case 2:
            removeElementoListaSimples(&pLista);
            break;
        case 3:
            mostraSoma(&pLista);
            break;
        case 4:
            buscaListaSimples(&pLista);
            break;
        case 0:
            exit(0);

        case 5:
            break;
        }
    }
    return 0;
}
