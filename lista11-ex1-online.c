/*
01 – Faça um programa que leia 5 nomes e mostre-os em ordem alfabética. Utilize o algoritmo de ordenação Insertion Sort. 
*/
// C program for insertion sort
#include <stdio.h>
void insertionSort(int vet[], int n);
void printArray(int vet[], int n);

/* Driver program to test insertion sort */
int main()
{
    int n;
    scanf("%d", &n);
    int vet[n];
    n = sizeof(vet) / sizeof(vet[0]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    insertionSort(vet, n);
    printArray(vet, n);

    return 0;
}

/* Function to sort an vetay using insertion sort*/
void insertionSort(int vet[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = vet[i];
        j = i - 1;

        /* Move elements of vet[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
        while (j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}
// A utility function to print an array of size n
void printArray(int vet[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}