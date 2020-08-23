/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int code_city[5], veiculos[5], acidentes[5], maior_ac = 0, menor_ac = 0, flag_maior = 0, flag_menor = 0, j = 0;
    float media_vei = 0, media_ac = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &code_city[i]);
        scanf("%d", &veiculos[i]);
        scanf("%d", &acidentes[i]);
        media_vei += veiculos[i];
        if (veiculos[i] < 2000)
        {
            media_ac += acidentes[i];
            j++;
        }
    }
    media_vei = media_vei / 5;
    maior_ac = acidentes[0];
    menor_ac = acidentes[0];
    media_ac = media_ac / j;
    for (int i = 0; i < 5; i++)
    {
        if (acidentes[i] > maior_ac)
        {
            maior_ac = acidentes[i];
            flag_maior = i;
        }
        if (acidentes[i] < menor_ac)
        {
            menor_ac = acidentes[i];
            flag_menor = i;
        }
    }
    printf("A cidade com o MAIOR numero de acidentes é a cidade %d possuindo %d acidentes\n", code_city[flag_maior], maior_ac);
    printf("A cidade com o MENOR numero de acidentes é a cidade %d possuindo %d acidentes\n", code_city[flag_menor], menor_ac);
    printf("A media de veiculos das cinco cidades juntas é de: %.2f\n", media_vei);
    printf("A media de acidentes em cidades com número menor de 2000 veiculos é de %.2f acidentes\n", media_ac);
    return 0;
}