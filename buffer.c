/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite  %d° caracter: ", i + 1);
        scanf("%c", &ch);
        fread(&ch, sizeof(char), 1, stdin);
    }
    return 0;
}