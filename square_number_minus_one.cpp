/*

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    double z = 1;
    printf("\n");
    printf("Voce sabia que dado um numero, elevado ao quadrado, ele sempre sera +1, do que a multiplicacao dos seus laterais?\n\n");
    printf("Veja por si proprio... Digite um numero para ser elevado ao quadrado: ");
    cin >> x;
    y = (x - 1) * (x + 1);
    z = pow(x, 2);
    printf("%d elevado ao quadrado = %.0lf\n", x, z);
    printf("e %d x %d = %d\n\n", x - 1, x + 1, y);
    printf("Ate a proxima! :)\n");

    return 0;
}