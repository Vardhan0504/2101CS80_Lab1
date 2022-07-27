#include <stdio.h>

// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, element, j;
    for (i = 1; i < n; i++)
    {
        element = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > element)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = element;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int x;
    printf("Enter 1 for Insertion Sort\n");
    printf("Enter 2 for Selection Sort\n");
    printf("Enter 3 for Bubble Sort\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        insertionSort(array, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    case 2:
        selectionSort(array, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    case 3:
        bubbleSort(array, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
