#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

typedef struct
{
    int topo;
    int dados[max];
} stack;

void push(stack *p, int x)
{
    (*p).topo++;
}

int pop(stack *p)
{
    return (*p).topo--;
}

int main()
{
    int inv = 0;
    char exp[1000];
    stack pilha;
    pilha.topo = -1;
    while (fgets(exp, 100, stdin))
    {

        for (int i = 0; i < strlen(exp) - 1; i++)
        {
            if (exp[i] == '(')
            {
                push(&pilha, exp[i]);
            }
            if (exp[i] == ')')
            {
                inv = pop(&pilha);
                if (inv == -1)
                {
                    printf("incorrect\n");
                    exit(0);
                }
            }
        }

        if (pilha.topo == -1)
        {
            printf("correct\n");
        }
        else
        {
            printf("incorrect\n");
        }
    }
    return 0;
}