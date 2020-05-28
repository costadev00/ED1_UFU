/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char frase[100], codigo[100];
    scanf("%[^\n]", frase);
    int i = 0;
    do
    {

        while (frase[i] == 'a' || frase[i] == 'A')
        {
            codigo[i] = '.';
            i++;
            codigo[i] = '-';
            i++;
        }
        while (frase[i] == 'b' || frase[i] == 'B')
        {
            codigo[i] = '-';
            i++;
            codigo[i] = '.';
            i++;
            codigo[i] = '.';
            i++;
            codigo[i] = '.';
            i++;
        }
        // if (frase[i] == " ")
        // {
        //     codigo[i] = ' ';
        //     // i++;
        // }
        // frase[i] = (frase[i] + acm_frase);
    } while (frase[i] != '\0');
    printf("%s\n", codigo);
    return 0;
}