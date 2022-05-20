/**
 * @file Bintree_problem.cpp
 * @author Chena
 * @brief 求二叉树最大节点层问题
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#define MAXSIZE 100

// 二叉树定义
typedef struct BTNode
{
    char data;
    struct BTNode * lchild;
    struct BTNode * rchild;
}BTNode;

typedef struct 
{
    /* data */
    BTNode *p;
    int level;
}St;


int maxNode(BTNode *p)
{
    St queue[MAXSIZE];
    int front, rear;
    int Level;
    front = rear = 0;
    BTNode * q;

    if(p != NULL)
    {
        rear++;
        queue[rear].p = p;
        queue[rear].level = 1;

        while(front != rear)
        {
            front++;
            q = queue[front].p;
            Level = queue[front].level;

            if(q->lchild != NULL)
            {
                rear++;
                queue[rear].p = q->lchild;
                queue[rear].level = Level + 1;
            }

            if(q->rchild != NULL)
            {
                rear++;
                queue[rear].p = q->rchild;
                queue[rear].level = Level + 1;
            }
        }

        int max = 0;
        for(int i = 1; i <= Level; i++)
        {
            int n = 0;
            for(int j = 0; j < rear; j++)
            {
                if(queue[j].level == i)
                    n++;
            }
            if(max < n)
                max = n;
        }

        return max;
    }
    else
        return 0;
}


int main(void)
{


    
    return 0;
}



