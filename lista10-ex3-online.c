/*
03 – Crie uma função que conte os dígitos de um determinado número usando recursão. Exemplo: se o usuário inserir o número 450, a saída esperada deve ser : o número digitado tem 3 dígitos. 
*/
#include <stdio.h>
#include <stdlib.h>
int cont = 0;
int main()
{
    int n, res;
    scanf("%d", &n);
    res = contaDigitos(n);
    printf("%d\n", res);
    return 0;
}
int contaDigitos(int n)
{
    if (n > 0)
    {
        cont++;
        contaDigitos(n / 10);
    }
    return cont;
}