/*
01 – Crie uma função que faça a exponenciação de um número. Exemplo: a função recebe x = 2, y = 3, então será 2 elevado a 3 que é igual a 8, utilize a recursão. 
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, y, res;
    scanf("%d", &x);
    scanf("%d", &y);
    res = exponencial(x, y);
    printf("%d\n", res);
    return 0;
}
int exponencial(int x, int y)
{
    int res = 0;
    while (y >= 0)
    {
        res = x * x;
        y--;
    }
    return res;
}