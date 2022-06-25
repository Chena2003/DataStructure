#include <stdio.h>

// 希尔排序     直接插入排序改进版
void ShellSort(int arr[], int n)
{
    int i, j, temp;
    for(int gap = n/2; gap >= 1; gap = gap/2)
    {
        for(i = gap; i < n; i += gap)
        {
            if(arr[i] < arr[i-gap])
            {
                temp = arr[i];
                for(j = i-gap; j >= 0 && arr[j] > temp; j -= gap)
                {
                    arr[j+gap] = arr[j];
                }
                arr[j+gap] = temp;
            }
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

    ShellSort(arr, 9);

    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}
