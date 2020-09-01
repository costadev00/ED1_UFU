/*

*/
#include <iostream>
using namespace std;
int main()
{
    int num, valor;
    int *p;
    num = 55;
    p = &num;
    valor = *p;
    printf("Valor da variavel normal: %d\n", valor);
    printf("Enredeco para onde o ponteiro aponta: %p \n", p);
    printf("Valor da variavel apontada(ponteiro p): %d\n", *p);
}