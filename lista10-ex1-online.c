/*
01 – Crie uma função que faça a exponenciação de um número. Exemplo: a função recebe x = 2, y = 3, então será 2 elevado a 3 que é igual a 8, utilize a recursão. 
*/
#include <stdio.h>
#include <stdlib.h>
int pow(int base, int expoente)
{
    if (expoente == 0)
    {
        return 1;
    }
    return base * pow(base, expoente - 1);
}
int main()
{
    int x, base, expoente;
    printf("Informe a base e o expoente:\n");
    scanf("%d %d", &base, &expoente);
    x = pow(base, expoente);
    printf("Resultado: %d\n", x);
    return 0;
}