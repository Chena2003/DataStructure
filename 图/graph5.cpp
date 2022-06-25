/**
 * @file graph5.cpp
 * @author Chena
 * @brief 最短路径Dijkstra算法
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

typedef char VertexType;   // 顶点数据类型
typedef int  EdgeType;     // 边权值
#define  MAXVEX     100
#define  INFINITY   65535

typedef struct 
{
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType   arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numVertexes, numEdges;      // 图中当前顶点数和边数
}MGraph;

typedef int Patharc[MAXVEX]; // 存储最短路径下标数组
typedef int ShortPathTable[MAXVEX]; //用于存储各点最短路径的权值和

void Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
    int i, j, k, min;
    int final[MAXVEX];

    for(i = 0; i < G.numVertexes; ++i)
    {
        final[i] = 0;
        (*D)[i] = G.arc[v0][i];
        (*P)[i] = 0;
    }

    (*D)[v0] = 0;
    final[v0] = 1;

    for(i = 1; i < G.numVertexes; ++i)
    {
        min = INFINITY;
        for(j = 0; j < G.numVertexes; ++j)
        {
            if(!final[j] && (*D)[j] < min)
            {
                k = j;
                min = (*D)[j];
            }
        }

        final[k] = 1;
        for(j = 0; j < G.numVertexes; ++j)
        {
            if(!final[j] && (min + G.arc[k][j] < (*D)[j]))
            {
                (*D)[j] = min + G.arc[k][j];
                (*P)[j] = k;
            }
        }
    }
}
