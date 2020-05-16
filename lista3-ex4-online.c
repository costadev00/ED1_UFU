/*
04 – Faça um algoritmo que leia a idade em ano, mês e dias e crie uma função que mostre a idade
em dias.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ano = 0, mes = 0, dia = 0, res = 0;
    scanf("%d", &ano);
    scanf("%d", &mes);
    scanf("%d", &dia);
    res = converteIdade(ano, mes, dia);
    printf("%d\n", res);
    return 0;
}
int converteIdade(int anos, int meses, int dias)
{
    anos = anos * 365;
    meses = meses * 30;
    dias = dias + anos + meses;
    return dias;
}