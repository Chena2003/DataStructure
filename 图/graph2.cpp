/**
 * @file graph2.cpp
 * @author Chena
 * @brief  图的相邻表表示法
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;     // 顶点数据类型
typedef int  EdgeType;      // 边权值

#define MAXVEX 100

// 定义边表节点
typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

// 定义顶点表节点
typedef struct
{
    VertexType data;
    EdgeNode *firstType;
}AdjList[MAXVEX];

// 定义邻接表
typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

// 创建邻接表
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k, w;
    EdgeNode *e;
    printf("请输入定点数和边数:\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges);

    for(i = 0; i < G->numVertexes; i++)
    {
        scanf("%d", &G->adjList[i].data);
        G->adjList[i].firstType = NULL;        
    }

    for(k = 0; k < G->numEdges; k++)
    {
        printf("输入边(Vi, Vj)上的下标i, 下标j和权: \n");
        scanf("%d %d %d", &i, &j, &w);

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); 

        e->adjvex = j;
        e->weight = w;
        e->next = G->adjList[i].firstType;
        G->adjList[i].firstType = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode)); 

        e->adjvex = i;
        e->weight = w;
        e->next = G->adjList[j].firstType;
        G->adjList[j].firstType = e;        
    }
}

int visited[MAXVEX];// 访问标记数组

// 深度优先遍历算法
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = 1;
    printf("%d\n", GL.adjList[i].data);

    p = GL.adjList[i].firstType;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex);
        
        p = p->next;
    }
}

// 深度优先算法操作
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i = 0; i < GL.numVertexes; i++)
        visited[i] = 0;
    
    for(i = 0; i < GL.numVertexes; i++)
        if(!visited[i])
            DFS(GL, i);
}



// 广度优先算法操作
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    int queue[MAXVEX];
    int front, rear;
    front = rear = 0;

    for(i = 0; i < GL.numVertexes; i++)
        visited[i] = 0;

    for(i = 0; i < GL.numVertexes; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            printf("%d\n", GL.adjList[i].data);
            rear = (rear + 1) % MAXVEX;
            queue[rear] = i;

            while (front < rear)
            {
                front = (front + 1) % MAXVEX;
                i = queue[front];

                p = GL.adjList[i].firstType;

                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex] = 1;
                        printf("%d\n", GL.adjList->data);
                        rear = (rear + 1) % MAXVEX;
                        queue[rear] = i;                    
                    }
                    p = p->next;
                }
            }
        }
    }
}