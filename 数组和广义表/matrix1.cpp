/**
 * @file matrix.cpp
 * @author Chena
 * @brief 矩阵运算
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define maxsize 50

//矩阵转置
void trsmat(int A[][maxsize], int B[][maxsize], int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            B[j][i] = A[i][j];
}

//矩阵相加
void addmat(int A[][maxsize], int B[][maxsize], int C[][maxsize], int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// 矩阵乘法
void mutimat(int A[][maxsize], int B[][maxsize], int C[][maxsize], int m, int k, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for(int h = 0; h < n; h++)
                C[i][j] += A[i][h] * B[h][j];
        }
    }
}

// 打印矩阵
void showmat(int A[][maxsize], int m , int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int A[maxsize][maxsize], B[maxsize][maxsize], C[maxsize][maxsize];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            A[i][j] = j + 6 * i;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            B[i][j] = j + 6 * i + 2 * (i + j);
        }
    }

    showmat(A, 5, 6);
    putchar('\n');
    showmat(B, 5, 6);
    putchar('\n');
    trsmat(A, C, 5, 6);
    showmat(C, 5, 6);
    putchar('\n');
    addmat(A, B, C, 5, 6);
    showmat(C, 5, 6);
}