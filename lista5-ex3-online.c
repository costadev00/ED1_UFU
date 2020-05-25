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
    int *p1, *p2;
    printf("digite o valor de x: \n");
    scanf("%d", &x); //1
    printf("digite o valor de y: \n");
    scanf("%d", &y); //2
    p1 = &x;
    p2 = &y;
    trocaNumeros(*p1, *p2);
    return 0;
}
void trocaNumeros(x1, y1)
{
    printf("trocando os valores...\n");
    int temp;
    temp = x1;
    x1 = y1;
    y1 = temp;
    printf("x = %d\n", x1);
    printf("y = %d\n", y1);
}