#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0, v = 0;
    long fat;
    printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    scanf("%d", &n);
    fat = 1;
    v = n;
    while (v > 1)
    {
        // printf("%d * %d\n", n, fat);
        fat = fat * v;
        printf("%d x %d = %d\n", n, v, fat);
        v--;
    }
    printf("\n");
    printf("Fatorial de %d = %d\n\n", n, fat);
    return 0;
}