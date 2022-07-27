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

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    printf("Enter 4 for Merge Sort\n");

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
    case 4:
        mergeSort(array, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
