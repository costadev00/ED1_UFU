/*
 03 – Faça um algoritmo que peça ao usuário o valor de uma variável x e depois de uma y. Crie
uma função que inverta esses valores através do uso de ponteiros. exemplo: X = 1, Y = 2, após a
troca deverá ficar desta forma X=2, Y=1.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, y;
    int *res;
    scanf("%d", &x); //1
    scanf("%d", &y); //2
    trocaNumeros(x, y);
    return 0;
}
void trocaNumeros(x1, y1)
{
    int *pointx, *pointy;
    pointx = y1;
    pointy = x1;
    printf("x = %d\n", pointx);
    printf("y = %d\n", pointy);
}