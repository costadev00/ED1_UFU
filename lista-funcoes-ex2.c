/*

*/
#include <stdio.h>
#include <stdlib.h>
int maiorNum(int n1, int n2);
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("O maior numero é: %d\n", maiorNum(x, y));
    return 0;
}

int maiorNum(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {

        return n2;
    }
}