// This is code to perform quicksort using the common used way I kept finding online, which uses 3 functions
// Feels free to check quickSort_single_fucntion.c to find how to shorten the code written and make it neat
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

int partition(int *arrNum, int low, int high)
{
    int pivot = arrNum[high];
    printf("pivot inside is %d\n", high);
    int i = low;

    // printf("%d\n", - 1 + 1);

    for(int j = low; j < high; j++)
    {
        if(arrNum[j] <= pivot)
        {
            swap(&arrNum[i], &arrNum[j]);
            i += 1;
        }
    }

    swap(&arrNum[i], &arrNum[high]);

    return i;
}

int quickSort_recursion(int *arrNum, int low, int high)
{

    if(low < high)
    {
        int pivot = partition(arrNum, low, high);
        printf("pivot is %d\n", pivot);
        quickSort_recursion(arrNum, low, pivot - 1);
        quickSort_recursion(arrNum, pivot + 1, high);
    }
}

int quickSort(int *arrNum, int size)
{
    quickSort_recursion(arrNum, 0, size - 1);
}

int main()
{
    // int arrNum[5] = {4, 2, 5, 3, 1};
    int arrNum[7] = {7, 4, 2, 5, 6, 3, 9};
    int size = 7;
    // int sortedArr[size];

    quickSort(arrNum, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arrNum[i]);
    }

    return 0;
}