/*
02 – Faça um programa que organize um vetor de inteiros em ordem crescente. Utilize o algoritmo de ordenação Bubble Sort. 
*/
// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>

// Prototipes
void printArray(int arr[], int size);
void bubbleSort(int arr[], int n);

// Driver program to test above functions
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int aux = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            //compair with the next element
            if (arr[j] > arr[j + 1])
            {
                //and if true, you can swap them
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}