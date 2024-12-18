// This is code to perform quicksort using one function only instead of using 3 as shown in qsort_common_way
// I would like to thank Bro Code channel for the great explanation of quicksort which can be found here 
// https://www.youtube.com/watch?v=Vtckgz38QHs

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int quickSort(int *arr, int low, int high)
{
    int pivot = high;
    int i = low - 1;
    if(low < high)
    {
        for(int j=low; j<=pivot; j++)
        {
            if(arr[j] < arr[pivot])
            {
                i++;
                printf("%d\n", i);
                swap(&arr[i], &arr[j]);
            }
        }

        i++;
        swap(&arr[i], &arr[pivot]);

        pivot = i;

        // recursion
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

    return 0;
}

int main()
{
    // int arr[5] = {2, 5, 3, 1, 4};

    int arr[30];

    // Generate 30 random integers and store them in the array
    for(int i = 0; i < 30; i++)
    {
        arr[i] = rand() % 100 + 1;  // Random number between 1 and 100
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for(int i=0; i<size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}