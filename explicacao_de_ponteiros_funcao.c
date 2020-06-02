#include <stdio.h>
#include <stdlib.h>
int main()
{
    int valor = 10;
    modifica(&valor);
    printf("%d\n", valor);
    return 0;
}
void modifica(int *x)
{
    *x = *x + 2;
}