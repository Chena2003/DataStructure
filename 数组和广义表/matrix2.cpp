/**
 * @file matrix2.cpp
 * @author Chena
 * @brief 三元法表示矩阵
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define maxsize 50

// 三元结构体
typedef struct 
{
    int val;
    int i, j;
}Trimat;

// 创建三元组
void createtrimat(int A[][maxsize], int m, int n, int B[][3])
{
    int k = 1;
    for(int i=0; i < m; i++)
        for(int j=0; j<n; j++)
            if(A[i][j] != 0)
            {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
                ++k;
            }
        
    B[0][0] = k - 1;
    B[0][1] = m;
    B[0][2] = n;
}

void print(int B[][3])
{
    int k = 1;
    for(int i = 0; i < B[0][1]; ++i)
    {
        for(int j = 0; j < B[0][2]; ++j)
        {
            if(i == B[k][1] && j == B[k][2])
            {
                printf("%4d", B[k][0]);
                k++;
            }
        }
        putchar('\n');
    }
}

int main(void)
{
    // Trimat trimat[maxsize];
    // 简易表示法
    int trimat[maxsize+1][3];
    int A[maxsize][maxsize];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 6; j++)
            A[i][j] = 6 * i + j + 1;
    

    createtrimat(A, 5, 6, trimat);
    print(trimat);

    return 0;
}