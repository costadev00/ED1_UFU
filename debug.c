#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //abrir um arquivo
    FILE *f, *g;
    int v, mat[3][5], vet[15], i, soma = 0;
    f = fopen("arq.txt", "r");
    // g = fopen("narq.txt", "w");
    if (f == NULL || g == NULL)
    {
        printf("Erro na abertura\n");
    }

    // i = 0;
    while (!feof(f))
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; i++)
            {
                fscanf(f, "%i", &v);
                mat[i][j] = v;
            }
            // }
            // printf("%i ", v);
            // i++;
        }
    }
    for (i = 0; i < 5; i++)
    {
        soma = 0;
        for (int j = 0; j < 3; j++)
        {
            soma = soma + mat[i][j];
        }
        printf("Linha %i = %i\n", i, soma);
        fopen("narq.txt", "a+");
        fprintf(f, "Soma = %d\n", soma);
        fclose(f);
    }
    // printf("\n %i ", soma);
    // fclose(f);
    // fclose(g);
    return 0;
}
