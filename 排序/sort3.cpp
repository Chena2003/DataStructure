/**
 * @file sort3.cpp
 * @author Chena
 * @brief 堆排序
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

// 建堆
void HeapAdjust(int arr[], int i, int n)
{
    int temp, j;
    temp = arr[i];

    for(j = i*2; j < n; j *= 2)
    {
        if(j < n && arr[j] < arr[j+1])
            ++j;
        
        if(temp >= arr[j])
            break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

// 堆排序
void HeapSort(int arr[], int n)
{
    int i, temp;

    for(i = n/2; i >= 0; i--)
        HeapAdjust(arr, i, n);
    
    for(i = n-1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        HeapAdjust(arr, 0, i-1);
    }
}


int main(void)
{

    int arr[20] = {50,10,90,30,70,40,80,60,20};
    int n = 9;

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    HeapSort(arr, 9);

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);



    return 0;
}