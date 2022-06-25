#include <stdio.h>

// 冒泡排序
void BubbleSort(int arr[], int n)
{
    int i, j;
    int flag = 1;

    for(i = 1; i < n && flag; ++i)
    {
        flag = 0;
        for(j = n-1; j >= i; --j)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;

                flag = 1;
            }
        }
    }
}

// 简单选择排序
void SelectSort(int arr[], int n)
{
    int i, j, min;

    for(i = 0; i < n-1; ++i)
    {
        min = i;
        for(j = i+1; j < n; ++j)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }

        if(min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

// 直接插入排序
void InsertSort(int arr[], int n)
{
    int i, j;
    for(i = 1; i < n; ++i)
    {
        if(arr[i] < arr[i-1])
        {
            int temp = arr[i];
            for(j=i-1; j >= 0 && arr[j] > temp; --j)
                arr[j+1] = arr[j];
            arr[j+1] = temp;
        }
    }
}



int main(void)
{
    int arr[20] = {50,10,90,30,70,40,80,60,20};
    int n = 9;

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    InsertSort(arr, 9);

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);


    return 0;
}