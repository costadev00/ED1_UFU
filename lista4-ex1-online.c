/*
01 – Faça um algoritmo que peça uma senha para o usuário e verifique se a senha digitada foi “d4t5r”, caso esteja correta mostre na tela “Acesso Permitdo”, caso esteja errada “Acesso
Negado ”. Obs: caso contenha mais de 4 digitos digitos mostre “Acesso Negado ” e peça para o
usúario uma nova senha.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char senha[] = "d4t5r", valor[80];
    int tamanho;
    do
    {
        printf("Digite uma senha\n");
        scanf("%s", valor);
        tamanho = strlen(valor);
        if (strcmp(senha, valor) == 0)
        {
            printf("Acesso permitido\n");
            break;
        }
        if (tamanho > 5)
        {
            printf("Acesso Negado\n");
            continue;
        }
        printf("Acesso Negado\n");
    } while (strcmp(senha, valor) != 0);
    return 0;
}
// fflush(stdout);