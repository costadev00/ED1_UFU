/*
5- Faça um algoritmo que leia um vetor até que o usuário digite 0 para encerrar a leitura e mostre a
quantidade de números ímpares e pares.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet[999], i = 0, enc = 0, acm_par = 0, acm_impar = 0;
    do
    {
        printf("digite o valor do vet[%d]", i);
        scanf("%d", &vet[i]);
        i++;
        if (vet[i] % 2 == 0)
        {
            acm_par++;
        }
        else
        {
            acm_impar++;
        }
        printf("digite 0 para encerrar o programa\n");
        scanf("%d", &enc);
    } while (enc != 0);
    printf("a quantidade de elementos par:%d\n", acm_par);
    printf("a quantidade de elementos impar:%d\n", acm_impar);
    return 0;
}