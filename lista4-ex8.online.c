/*
08 – Faça um algoritmo que realize o cadastro de 4 alunos, contendo número de matricula, curso e
3 notas. Faça uma função que calcule a média das notas e faça outra função para mostrar todos os
dados de cada aluno cadastrado. No final deve mostrar uma mensagem de parabéns em seguida o
número de matricula de quem ficou com a maior média.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char matricula[50];
    char curso[50];
    float notas[3];
} Aluno;
float calculeMedia(Aluno);
void mostrarAluno(Aluno);
int main()
{
    float medias[4];
    Aluno a[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%s", &a[i].matricula);
        scanf("%s", &a[i].curso);
        scanf("%.2f", &a[i].notas[0]);
        scanf("%.2f", &a[i].notas[1]);
        scanf("%.2f", &a[i].notas[2]);
        medias[i] = calculeMedia(a[i]);
    }
    float maior = 0;
    for (int i = 0; i < 4; i++)
    {
        mostrarAluno(a[i]);
        if (medias[i] > maior)
        {
            maior = medias[i];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (medias[i] == maior)
        {
            printf("Parabéns!\n");
            printf("%s\n", a[i].matricula);
            // printf("%f", maior);
        }
    }
    return 0;
}
float calculeMedia(Aluno a1)
{
    return (a1.notas[0] + a1.notas[1] + a1.notas[2]) / 3;
}
void mostrarAluno(Aluno a2)
{
    printf("Matricula: ");
    puts(a2.matricula);
    printf("Curso: ");
    puts(a2.curso);
    printf("Notas: ");
    printf("%.2f\n", a2.notas[0]);
    printf("%.2f\n", a2.notas[1]);
    printf("%.2f\n", a2.notas[2]);
}