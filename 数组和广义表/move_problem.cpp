#include <stdio.h>

/*
将数组中所用的非零元素移动到数组前端
*/
void movement1(int A[], int n)
{
    int i = -1, j, temp;
    for(j = 0; j < n; j++)
    {
        if(A[j] != 0)
        {
            i++;    // 不为0元素的个数
            // i, j不相等则互换
            if(i != j)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void movement2(int A[], int n)
{
    int i = 0, j = n - 1, temp;
    while(i < j)
    {
        while(A[i] % 2 == 1 && i < j)
            i++;
        while(A[i] % 2 == 0 && i < j)
            j--;

        if(i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } 
}

void movement3(int A[], int n)
{
    int temp = A[n-1];
    A[n-1] = A[0];
    A[0] = temp;
    int i = 0, j = n-1;

    while(i < j)
    {
        while(A[j] > temp && i < j)
            j--;
        if(i < j)
        {
            A[i] = A[j];
            i++;
        }

        while(A[i] <= temp && i < j)
            i++;
        if(i < j)
        {
            A[j] = A[i];
            j--;
        }
    }
    A[i] = temp;
}

int main(void)
{
    return 0;
}