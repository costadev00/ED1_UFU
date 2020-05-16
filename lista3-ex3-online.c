/*
03 – Faça um algoritmo que peça uma senha para o usuário e faça uma função que verifique se a
senha digita foi 4389, se estiver correta mostre na tela “Acesso Permitdo”, caso esteja errada
“Acesso Negado ”.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int senha = 0, acesso = 0;
    scanf("%d", &senha);
    verificaSenha(senha);
    return 0;
}
void verificaSenha(int passwd)
{
    if (passwd == 4389)
    {
        printf("Acesso Permitido\n");
    }
    else
    {
        printf("Acesso Negado\n");
    }
}