#include <stdio.h>
#include <stdlib.h>

int main()
{
    float custo_de_fabrica, custo_consumidor, porcentagem_dist, impostos;
    scanf("%f",&custo_de_fabrica);
    porcentagem_dist = (28 * custo_de_fabrica) /100;
    impostos = (45 * custo_de_fabrica) /100;
    custo_consumidor = custo_de_fabrica + porcentagem_dist + impostos;
    printf("%.2f", custo_consumidor);
    return 0;
}
