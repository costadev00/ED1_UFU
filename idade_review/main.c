#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ano_nasc, mes_nasc, dia_nasc,idade,anos, meses,dias;
    scanf("%d",&ano_nasc);
    scanf("%d",&mes_nasc);
    scanf("%d",&dia_nasc);
    anos = ano_nasc*360;
    meses = mes_nasc*30;
    dias = dia_nasc;
    idade = anos + meses + dias;
    printf("a sua idade em dias eh %d", idade);
    return 0;
}
