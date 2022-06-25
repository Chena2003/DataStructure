/**
 * @file graph6.cpp
 * @author Chena
 * @brief 最短路径Floyd算法
 * @version 0.1
 * @date 2022-06-18
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

typedef int PathMatirx[MAXVEX][MAXVEX]; // 存储最短路径下标数组
typedef int ShortPathTable[MAXVEX][MAXVEX]; //用于存储各点最短路径的权值和

void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges=16;
	G->numVertexes=9;

	for (i = 0; i < G->numVertexes; i++)
	{
		G->vexs[i]=i;
	}

	for (i = 0; i < G->numVertexes; i++)
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 

	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;

	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;

	G->arc[7][8]=4;


	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}

void Floyd(MGraph G, PathMatirx *P, ShortPathTable *D)
{
    int i, j, k;

    for(i = 0; i < G.numVertexes; ++i)
    {
        for(j = 0; j < G.numVertexes; ++j)
        {
            (*D)[i][j] = G.arc[i][j];
            (*P)[i][j] =  j;
        }
    }

    for(k = 0; k < G.numVertexes; ++k)
    {
        for(i = 0; i < G.numVertexes; ++i)
        {
            for(j = 0; j < G.numVertexes; ++j)
            {
                if((*D)[i][j] > ((*D)[i][k] + (*D)[k][j]))
                {
                    (*D)[i][j] = (*D)[i][k] + (*D)[k][j];
                    (*P)[i][j] = (*P)[i][k];
                }
            }
        }
    }
}


void printPath(PathMatirx P, ShortPathTable D, int u, int v)
{
    if(P[u][v] == v)
    {
        printf("v%d-v%d weight: %d \n", u, v, D[u][v]);
    }
    else
    {
        int mid = P[u][v];
        printPath(P, D, u, mid);
        printPath(P, D, mid, v);
    }
}


int main(void)
{
    PathMatirx P;
    ShortPathTable D;
    MGraph G;
    int i, j;

    CreateMGraph(&G);

    Floyd(G, &P, &D);

    // for(i = 0; i < G.numVertexes; ++i)
    // {
    //     for(j = 0; j < G.numVertexes; ++j)
    //     {
    //         printf("%d\t", P[i][j]);
    //     }
    //     printf("\n");
    // }

    printPath(P, D, 0, 8);

    return 0;
}