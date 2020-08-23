/*

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet1[5], vet2[5], n;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vet1[i]);
    }
    printf("Digite abaixo um valor a ser apagado do vetor:\n");
    scanf("%d", &n);
    for (int i = 0; i < 5; i++)
    {
        if (vet1[i] == n)
        {
            i++;
        }
        vet2[i] = vet1[i];
        printf("%d\n", vet2[i]);
    }
    return 0;
}