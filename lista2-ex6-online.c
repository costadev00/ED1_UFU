/*
6- Faça um algoritmo que tenha 3 opções:
1 - Somar 3 números.
2 - Subtrair 3 números.
0 - Sair
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int opcao, num1, num2, num3;
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    do
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("%d\n", num1 + num2 + num3);
            break;

        case 2:
            printf("%d\n", num1 - num2 - num3);
            break;

        case 0:
            // code
            break;
        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}