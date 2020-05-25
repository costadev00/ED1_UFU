#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int valor = 10;
    ptr = &valor;
    printf("Endereco real = %d\n", &valor);
    printf("Endereco apontado = %d\n", ptr);
    printf("Valor = %d\n", *ptr);
    return 0;
}