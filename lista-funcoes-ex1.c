/*

*/
#include <stdio.h>
#include <stdlib.h>

float calcula_nota(float n1, float n2, float n3);
void printMedia(float num);
int main()
{
    float n1, n2, n3, total = 0;
    scanf("%f %f %f", &n1, &n2, &n3);
    total = calcula_nota(n1, n2, n3);
    if (total >= 8.1 && total <= 10.0)
    {
        printMedia(total);
        printf("Conceito A\n");
    }
    else if (total >= 7.1 && total <= 8.0)
    {
        printMedia(total);
        printf("Conceito B\n");
    }
    else if (total >= 6.1 && total <= 7.0)
    {
        printMedia(total);
        printf("Conceito C\n");
    }
    else if (total >= 5.1 && total <= 6.0)
    {
        printMedia(total);
        printf("Conceito D\n");
    }
    else
    {
        printMedia(total);
        printf("Conceito E\n");
    }
    return 0;
}

float calcula_nota(float n1, float n2, float n3)
{
    float media = 0;
    n1 *= 2;
    n2 *= 3;
    n3 *= 5;
    media = (n1 + n2 + n3) / 10;
    return media;
}
void printMedia(float num)
{
    printf("Media = %.2f\n", num);
}