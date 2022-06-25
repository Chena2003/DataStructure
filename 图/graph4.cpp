/**
 * @file graph3.cpp
 * @author Chena
 * @brief 最小生成树Prim算法
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

typedef struct 
{
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType   arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numVertexes, numEdges;      // 图中当前顶点数和边数
}MGraph;


int Prim(MGraph G, int v0)
{
    int lowCost[MAXVEX], vSet[MAXVEX];
    int i, v, k, min, sum;

    for(i = 0; i < G.numVertexes; ++i)
    {
        lowCost[i] = G.arc[v0][i];
        vSet[i] = 0;
    }

    v = v0;
    vSet[v] = 1;
    sum = 0;

    for(i = 0; i < G.numVertexes; ++i)
    {
        min = INFINITY;

        for(int j = 0; j < G.numVertexes; ++j)
        {
            if(vSet[j] == 0 && lowCost[j] < min)
            {
                min = lowCost[j];
                k = j;
            }
        }

        vSet[k] = 1;
        v = k;
        sum += min;
        for(int j = 0; j < G.numVertexes; ++j)
        {
            if(vSet[j] == 0 && G.arc[v][j] < lowCost[j])
                lowCost[j] = G.arc[v][j];
        }
    }

    return sum;
}