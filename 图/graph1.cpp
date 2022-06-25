/**
 * @file graph1.cpp
 * @author Chena
 * @brief 图的相邻矩阵表示法
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

typedef char VertexType;   // 顶点数据类型
typedef int  EdgeType;     // 边权值
#define  MAXVEX     100
#define  INFINITY   65535


typedef  struct 
{
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType   arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numVertexes, numEdges;      // 图中当前顶点数和边数
}MGraph;


// 创建相邻矩阵
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数和边数:\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges);

    for(i = 0; i < G->numVertexes; i++)
        scanf("%d", &G->vexs[i]);
    for(i = 0; i < G->numVertexes; i++)
        for(j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    
    for(k = 0; k < G->numEdges; k++)
    {
        printf("输入边(Vi, Vj)上的下标i, 下标j和权: \n");
        scanf("%d %d %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}


int visited[MAXVEX];  // 访问标记数组

// 深度优先遍历算法
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = 1;
    printf("%d\n", G.vexs[i]);
    for(j = 0; j < G.numVertexes; j++)
    {
        if(G.arc[i][j] = 1 && !visited[j])
            DFS(G, j);
    }
}

// 深度优先算法操作
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0; i < G.numVertexes; i++)
        visited[i] = 0;
    
    for(i = 0; i < G.numVertexes; i++)
        if(!visited[i])
            DFS(G, i);
}


// 广度优先算法操作
void BFSTraverse(MGraph G)
{
    int i, j;
    int queue[MAXVEX];
    int front, rear;
    front = rear = 0;

    for(i = 0; i < G.numVertexes; i++)
        visited[i] = 0;

    for(i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            printf("%d\n", G.vexs[i]);

            rear = (rear + 1) % MAXVEX;
            queue[rear] = i;

            while (front < rear)
            {
                front = (front + 1) % MAXVEX;
                i = queue[rear];

                for(j = 0; j < G.numVertexes; j++)
                {
                    if(G.arc[i][j] = 1 && !visited[j])
                    {
                        visited[j] = 1;
                        printf("%d\n", G.vexs[j]);
                        rear = (rear + 1) % MAXVEX;
                        queue[rear] = j;                        
                    }
                }
            }
        }
    }
}



