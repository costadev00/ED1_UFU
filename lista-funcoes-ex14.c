#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dobra(char p[]);

int main()
{
    char str[100];
    gets(str);
    strcat(str, " ");
    dobra(str);

    return 0;
}

void dobra(char p[])
{

    char str[50], strf[50];
    int j = 0;

    memset(str, 0, 50);
    memset(strf, 0, 50);

    for (int i = 0; i < strlen(p); i++)
    {

        if (p[i] != ' ')
        {
            str[j] = p[i];
            j++;
        }
        else
        {
            strcat(strf, str);
            strcat(strf, " ");
            strcat(strf, str);
            strcat(strf, " ");
            memset(str, 0, 50 * sizeof(char));
            j = 0;
        }
    }
    printf("%s", strf);
}