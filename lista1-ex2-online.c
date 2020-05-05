#include <stdio.h>
#include <stdlib.h>
int main()
{
    double n1, n2, media;
    int opcao;
    scanf("%d", &opcao);
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    switch (opcao)
    {
    case 1:
        media = (n1 / n2) / 2;
        printf("%.2lf\n", media);
        break;
    case 2:
        if (n1 > n2)
        {
            printf("%.2lf\n", n1 - n2);
        }
        else
        {
            printf("%.2lf\n", n2 - n1);
        }
        break;

    case 3:
        printf("%.2lf\n", n1 * n2);
        break;

    case 4:
        printf("%.2lf\n", n1 / n2);
        break;
    default:
        printf("digite uma entrada válida\n");
        break;
    }
    return 0;
}