/*
Lista de Exercícios de Estruturas de Dados 1 

Trabalho Final

Faça um algoritmo para uma livraria. Em uma lista duplamente encadeada cadastre os livros com as seguintes características:
● código do livro
● nome
● categoria(romance ficção, etc...)
● número de páginas
● resumo
● preço
● quantidade que possui no estoque.
 OBS: os livros devem ser ordenados pelo nome. 

O algoritmo deve conter as opções de: 
● Adicionar livro 
● Consultar livro através do nome 
● Mostrar todos os nomes dos livros 
● Vender livro(deverá diminuir na quantidade do livro que possui no estoque) 

-----------------------------------------------------------------------------
➢ OPÇÃO EXTRA - 5 PONTOS: ➢ Mostrar relatório com as vendas que foram efetuadas, deve ser salvo em um arquivo .txt 
o código, nome e a quantidade que foi vendida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TRABALHO_FINAL.h"
int main()
{
    //declaracoes
    no *pLista;
    int opcao = 0;

    //instrucoes
    initLista(&pLista);
    printf("\t ---- BEM VINDO A LIVRARIA DO COSTA ----");

    do
    {
        printf("Digite uma opcao:\n");
        printf("\n1 - Cadastrar um novo livro");
        printf("\n2 - Pesquisar pelo livro");
        printf("\n3 - Mostrar livros presentes na livraria");
        printf("\n4 - Vender livro");
        printf("\n5 - Mostrar relatórios de venda mensal\n");
        printf("\n0 - Sair da livraria\n");
        scanf("%d", &opcao);
        opcao = validaEntrada(&opcao);
        switch (opcao)
        {
        case 1:
            addLivro(&pLista);
            break;
        case 2:
            consultaNomeLivro(&pLista);
            break;
        case 3:
            mostraLivros(pLista);
            break;
        case 4:
            efetuarVenda(&pLista);
            break;
        case 5:
            mostraRelatorio_Vendas();
            break;
        case 0:
            printf("Obrigado por utilizar nossos serviços!!!\n");
        }
    } while (opcao != 0);

    return 0;
}