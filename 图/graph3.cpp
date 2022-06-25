/**
 * @file graph3.cpp
 * @author Chena
 * @brief 最小生成树Kruskal算法
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


typedef struct 
{
	int begin;
	int end;
	int weight;
}Edge;

/* 交换权值 以及头和尾 */
void Swapn(Edge *edges,int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

/* 对权值进行排序 */
void sort(Edge edges[],MGraph *G)
{
	int i, j;
	for ( i = 0; i < G->numEdges; i++)
	{
		for ( j = i + 1; j < G->numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("权排序之后的为:\n");
	for (i = 0; i < G->numEdges; i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}

}

int Find(int *parent, int f)
{
    while(parent[f] > 0)
        f = parent[f];
    return f;
}

void Kruskal(MGraph G)
{
    int i, j, n, m;
    Edge edges[MAXVEX];
    int parent[MAXVEX];
    int k = 0;

    for(i = 0; i < G.numVertexes-1; ++i)
    {
        for(j = i; j < G.numVertexes; ++j)
        {
            edges[k].begin = i;
            edges[k].end = j;
            edges[k].weight = G.arc[i][j];

            ++k;
        }
    }
    sort(edges, &G);

    for(i = 0; i < G.numVertexes; i++)
        parent[i] = 0;
    for(i = 0; i < G.numEdges; ++i)
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);

        if(n != m)
        {
            parent[n] = m;
            printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}


