#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float a, b, c;
    scanf("%d", &i);
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    if (a > b && a > c && b > c)
    {
        printf("%.2f\n", a);
        printf("%.2f\n", b);
        printf("%.2f\n", c);
    }
    if (a > b && a > c && c > b)
    {
        printf("%.2f\n", a);
        printf("%.2f\n", c);
        printf("%.2f\n", b);
    }
    if (b > a && b > c && a > c)
    {
        printf("%.2f\n", b);
        printf("%.2f\n", a);
        printf("%.2f\n", c);
    }
    if (b > a && b > c && c > b)
    {
        printf("%.2f\n", b);
        printf("%.2f\n", c);
        printf("%.2f\n", a);
    }
    if (c > a && c > b && a > b)
    {
        printf("%.2f\n", c);
        printf("%.2f\n", a);
        printf("%.2f\n", b);
    }
    if (c > a && c > b && a > b)
    {
        printf("%.2f\n", c);
        printf("%.2f\n", b);
        printf("%.2f\n", a);
    }
    return 0;
}
