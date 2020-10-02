#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

typedef struct
{
    int topo;
    char dados[max];

} stack;

void push(stack *p, char letra)
{
    p->dados[(++(*p).topo)] = letra;
}

char pop(stack *p)
{
    return ((*p).dados[(*p).topo--]);
}

int main()
{
    char letra, frase_fim[100], frase[] = "Eh mais dificil vencer habitos ruins do que despedacar pedras";
    int aux = 0, cont = 0, j = 0, k = 0, l = 0;
    stack pilha;
    pilha.topo = -1;

    memset(frase_fim, 0, 100 * sizeof(char));

    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] != ' ' && cont % 2 == 0)
        {
            push(&pilha, frase[i]);
            aux += 1;
        }
        else if (frase[i] != ' ' && cont % 2 == 1)
        {
            frase_fim[j] = frase[i];
            j++;
        }
        else
        {
            cont += 1;
            while (l < aux)
            {
                letra = pop(&pilha);
                frase_fim[j] = letra;
                j++;
                l++;
            }
            frase_fim[j] = ' ';
            j++;
            aux = 0;
            l = 0;
        }
    }
    puts(frase_fim);
    return 0;
}
