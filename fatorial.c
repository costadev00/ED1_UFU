#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    long fat;
    printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    scanf("%d", &n);
    fat = 1;
    while (n > 1)
    {
        fat = fat * n;
        n--;
    }

    printf("\nFatorial calculado: %d \n", fat);
    return 0;
}