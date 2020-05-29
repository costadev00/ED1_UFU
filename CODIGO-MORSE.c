#include <stdio.h>
#include <string.h>
#include <ctype.h>
static const struct
{
    const char letter, *morse;
} Code[] =
    {
        {'A', ".- "},
        {'B', "-... "},
        {'C', "-.-. "},
        {'D', "-.. "},
        {'E', ". "},
        {'F', "..-. "},
        {'G', "--. "},
        {'H', ".... "},
        {'I', ".. "},
        {'J', ".--- "},
        {'K', ".-.- "},
        {'L', ".-.. "},
        {'M', "-- "},
        {'N', "-. "},
        {'O', "--- "},
        {'P', ".--. "},
        {'Q', "--.- "},
        {'R', ".-. "},
        {'S', "... "},
        {'T', "- "},
        {'U', "..- "},
        {'V', "...- "},
        {'W', ".-- "},
        {'X', "-..- "},
        {'Y', "-.-- "},
        {'Z', "--.. "},
        {' ', "  "},
};
void codifica(const char *s)
{
    size_t i, j;
    for (i = 0; s[i]; ++i)
    {
        for (j = 0; j < sizeof Code / sizeof *Code; ++j)
        {
            if (toupper(s[i]) == Code[j].letter)
            {
                printf("%s", Code[j].morse);
                break;
            }
        }
    }
    putchar('\n');
}
void decodifica(const char *morse)
{
    printf("função decodifica\n");
    size_t i, j;
    for (i = 0; morse[i];)
    {
        for (j = 0; j < sizeof Code / sizeof *Code; ++j)
        {
            size_t size = strlen(Code[j].morse);
            if (memcmp(Code[j].morse, &morse[i], size) == 0)
            {
                putchar(Code[j].letter);
                i += size;
                break;
            }
        }
    }
    putchar('\n');
}
int main(void)
{
    int op = 0;
    char text[50];
    char test[50];
    printf("\t\t\t\tDigite sua opcao\n1_Codificar\n2_Decodificar\n:");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
    {
        printf("Digite seu texto a ser codificado\n");
        scanf(" %[^\n]", text);
        codifica(text);
        break;
    }
    case 2:
    {
        printf("Digite seu texto a ser decodificado\n");
        scanf(" %[^\n]", test);
        int len;
        len = strlen(test);
        if (test[len - 1] != ' ')
        {
            strcat(test, " "); //se falta space .. coloca um ;)
        }
        decodifica(test);
        break;
    }
    default:
    {
        printf("Vc digitou uma opcao nao correspondente!!");
        main();
        break;
    }
    }

    return 0;
}