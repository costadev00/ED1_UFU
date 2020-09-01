/*

*/
#include <stdio.h>
#include <stdlib.h>

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media);
int main()
{
    float p1, p2, p3, p4, *media;
    int faltas, aulas;
    scanf("%f", &p1);
    scanf("%f", &p2);
    scanf("%f", &p3);
    scanf("%d", &faltas);
    scanf("%d", &aulas);
    printf("A situacao do aluno eh: %c", situacao(p1, p2, p3, faltas, aulas, &media));
    return 0;
}

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media)
{
    float media_faltas;
    *media = (p1 + p2 + p3) / 3;
    media_faltas = aulas * (25 / 100);
    if (faltas > media_faltas)
    {
        return 'F';
    }
    if (media >= 6)
    {
        return 'A';
    }
    else
    {
        return 'R';
    }
}