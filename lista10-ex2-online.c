/*
02 – Crie uma função que faça a somatória de um número. Exemplo: x = 4, então a somatória será 4+3+2+1 = 10, utilize a recursão. 
*/
#include <stdio.h>
#include <stdlib.h>
int somatoria(int n);
int main()
{
    // S(n) = n+(n-1)+(n-2)+(n-3)+...+1
    int x, res = 0;
    scanf("%d", &x);
    res = somatoria(x);
    printf("%d\n", res);
    return 0;
}
int somatoria(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        return n + somatoria(n - 1);
    }
}