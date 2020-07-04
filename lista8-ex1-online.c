/*
01 – Faça um algoritmo que contenha as seguintes opções: 
1 - Inserir elemento na lista
2 - Retirar elemento da lista
3 - Mostrar elemento que está no início da lista 
0 - Sair 

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
        printf("\n2 - Consultar: ");
        printf("\n3 - Remover");
        printf("\n0 - Sair");
        printf("\n5 - Mostrar inicio\n");
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
            mostrarInicio(&pLista);
            break;
        case 0:
            exit(0);

        case 5:
            break;
        }
    }
    return 0;
}
