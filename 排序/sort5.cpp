/**
 * @file sort5.cpp
 * @author Chena
 * @brief 快速排序
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

void swap(int arr[], int n, int m)
{
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

int Partition(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    if(arr[low] > arr[high])
        swap(arr, low, high);
    if(arr[mid] > arr[high])
        swap(arr, mid, high);
    if(arr[mid] > arr[low])
        swap(arr, mid, low);

    int pivotkey = arr[low];

    while(low < high)
    {
        while(low < high && arr[high] >= pivotkey)
            high--;
        arr[low] = arr[high];

        while(low < high && arr[low] < pivotkey)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivotkey;

    return low;
}

void QSort(int arr[], int low, int high)
{
    int pivot;

    if(low < high)
    {
        pivot = Partition(arr, low, high);

        QSort(arr, low, pivot-1);
        QSort(arr, pivot+1, high);
    }
}


int main(void)
{

    int arr[20] = {50,10,90,30,70,40,80,60,20};
    int n = 9;

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    QSort(arr, 0, 8);

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);


    return 0;
}