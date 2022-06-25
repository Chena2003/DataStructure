/**
 * @file sort4.cpp
 * @author Chena
 * @brief 合并排序
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define MAXSIZE 100


void Merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[MAXSIZE], R[MAXSIZE];
    for(i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for(i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];
    
    i = 0;
    j = 0;
    k = low;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    
    while(j < n2)
        arr[k++] = R[j++];
}


void MSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        MSort(arr, low, mid);
        MSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}


int main(void)
{

    int arr[20] = {50,10,90,30,70,40,80,60,20};
    int n = 9;

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    MSort(arr, 0, 8);

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);


    return 0;
}