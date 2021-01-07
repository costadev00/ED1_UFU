/*
http://www.vision.ime.usp.br/~pmiranda/mac122_2s14/aulas/aula20/aula20.html
*/
#include <bits/stdc++.h>
using namespace std;

void Troca(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int SolucaoValida(int linhas[])
{
    int i;
    int x, y;
    int xx, yy;

    for (i = 0; i < 8; i++)
    {
        x = i;
        y = linhas[i];

        xx = x;
        yy = y;
        while (1)
        {
            xx += 1;
            yy -= 1;
            if (xx > 7 || yy < 0)
                break;

            if (yy == linhas[xx])
                return 0;
        }

        xx = x;
        yy = y;
        while (1)
        {
            xx -= 1;
            yy -= 1;
            if (xx < 0 || yy < 0)
                break;

            if (yy == linhas[xx])
                return 0;
        }
    }
    return 1;
}

void ImprimeSolucao(int linhas[])
{
    char tabuleiro[8][8];
    int i, j;
    int x, y;
    static int nsols = 0;

    nsols++;

    printf("******** SOL: %d ********\n", nsols);

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            tabuleiro[i][j] = '.';

    for (i = 0; i < 8; i++)
    {
        x = i;
        y = linhas[i];
        tabuleiro[y][x] = 'R';
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void TestaPermutacoes(int linhas[], int k)
{
    int i;

    if (k == 8)
    {
        if (SolucaoValida(linhas))
            ImprimeSolucao(linhas);
    }
    else
    {
        for (i = k; i < 8; i++)
        {
            Troca(linhas, k, i);
            TestaPermutacoes(linhas, k + 1);
            Troca(linhas, i, k);
        }
    }
}
void Solucoes8Rainhas()
{
    int linhas[8];
    int i;
    for (i = 0; i < 8; i++)
        linhas[i] = i;
    TestaPermutacoes(linhas, 0);
}

int main()
{

    Solucoes8Rainhas();
    return 0;
}