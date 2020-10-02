/*
03 – Faça um programa que organize um vetor de inteiros em ordem crescente. Utilize o algoritmo de ordenação Selection Sort.
*/
// C program for implementation of selection sort
#include <stdio.h>
#include <stdlib.h>
//Prototipes
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

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
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

void selectionSort(int arr[], int n)
{
    int aux = 0;
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        // Swap the found minimum element with the first element
        aux = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = aux;
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}