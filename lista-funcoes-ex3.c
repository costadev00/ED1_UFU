/*

*/
#include <stdio.h>
#include <stdlib.h>

float calcInv(int tipo, float valor);

int main()
{
    int tipo;
    float valor;
    scanf("%d", &tipo);
    scanf("%f", &valor);
    printf("O novo investimento = %.2f\n", calcInv(tipo, valor));
    return 0;
}
float calcInv(int tipo, float valor)
{
    float pct;
    if (tipo == 1)
    {
        pct = valor * (3 / 100);
        valor = valor + pct;
    }
    else if (tipo == 2)
    {
        pct = valor * (5 / 100);
        valor = valor + pct;
    }
    return valor;
}