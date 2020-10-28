/*
algoritmo que chama funcoes e as executa de forma recursiva
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0)
    {
        return n;
    }
    else if (n == 1)
    {
        return n;
    }

    return (fibo(n - 1) + fibo(n - 2));
}

int fat(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fat(n - 1);
    }
}
int potencia(int base, int expoente, int cont)
{

    if (cont == 0)
    {
        return 1;
    }
    else
    {
        cont--;
        return base * (potencia(base, expoente, cont));
    }
}

int somatoria(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + somatoria(n - 1);
}
int main()
{
    int opcao, res, n, base, expoente, cont = 0;
    do
    {
        cout << "\nDigite uma opcao:" << endl;
        printf("1 - Fibonacci\n");
        printf("2 - Fatorial\n");
        printf("3 - Potenciacao\n");
        printf("4 - Soma dos termos de uma sequencia\n");
        printf("0 - Encerrar o programa\n");
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite o n-esimo termo da serie fibonnacci que deseja encontrar\n";
            cin >> n;
            res = fibo(n);
            printf("O %d termo da serie eh: %d\n", n, res);
            break;
        case 2:
            cout << "Digite o fatorial de n a ser encontrado:\n";
            cin >> n;
            if (n < 0)
            {
                cout << "Não existe fatorial de número negativo\n";
                break;
            }
            res = fat(n);
            printf("%d! = %d\n", n, res);
            break;
        case 3:
            cout << "Digite a base\n";
            cin >> base;
            cout << "Digite o expoente\n";
            cin >> expoente;
            cont = expoente;
            res = potencia(base, expoente, cont);
            printf("%d elevado e %d = %d\n", base, expoente, res);
            break;
        case 4:
            cout << "Digite ate onde a sequencia deve ir:\n";
            cin >> n;
            res = somatoria(n);
            printf("A somatoria de %d ate 1 = %d", n, res);
            break;
        case 0:
            cout << "Ate a proxima!!!\n";
            break;
        default:
            cout << "Digite uma opcao valida\n";
            break;
        }
    } while (opcao != 0);
    return 0;
}