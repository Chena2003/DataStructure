/**
 * @file graph7.cpp
 * @author Chena
 * @brief 拓扑排序(AOV 网)
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define OK 1
#define ERROR 0
#define MAXVEX 100
#define INF 65535

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct EdgeNode
{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
}AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numVertexes = 14;
    G->numEdges = 20;

    for(i = 0; i < G->numVertexes; ++i)
    {
        G->vexs[i] = i;
        for(j = 0; j < G->numVertexes; ++j)
        {
            G->arc[i][j] = INF;
        }
    }

    
	G->arc[0][4]=1;
	G->arc[0][5]=1; 
	G->arc[0][11]=1; 
	G->arc[1][2]=1; 
	G->arc[1][4]=1; 
	G->arc[1][8]=1; 
	G->arc[2][5]=1; 
	G->arc[2][6]=1;
	G->arc[2][9]=1;
	G->arc[3][2]=1; 
	G->arc[3][13]=1;
	G->arc[4][7]=1;
	G->arc[5][8]=1;
	G->arc[5][12]=1; 
	G->arc[6][5]=1; 
	G->arc[8][7]=1;
	G->arc[9][10]=1;
	G->arc[9][11]=1;
	G->arc[10][13]=1;
	G->arc[12][9]=1;
}

void CreateALGraph(MGraph G,GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    GL->numVertexes = G.numVertexes;
    GL->numEdges = G.numEdges;

    for(i = 0; i < GL->numVertexes; ++i)
    {
        GL->adjList[i].data = G.vexs[i];
        GL->adjList[i].firstedge = NULL;
        GL->adjList[i].in = 0;
    }

    for(i = 0; i < G.numVertexes; ++i)
    {
        for(j = 0; j < G.numVertexes; ++j)
        {
            if(G.arc[i][j] == 1)
            {
                e = (EdgeNode * )malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->next = GL->adjList[i].firstedge;
                GL->adjList[i].firstedge = e;
                GL->adjList[j].in++;
            }
        }
    }
}

Status TopologicalSort(GraphAdjList *GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int *stack = (int *)malloc(GL->numVertexes * sizeof(int));

    for(i = 0; i < GL->numVertexes; ++i)
        if(GL->adjList[i].in == 0)
            stack[top++] = i;
    
    while(top != 0)
    {
        gettop = stack[--top];
        count++;
        if(count < GL->numVertexes)
            printf("%d -> ", GL->adjList[gettop].data);
        else
            printf("%d", GL->adjList[gettop].data);
        for(e=GL->adjList[gettop].firstedge; e; e=e->next)
        {
            k = e -> adjvex;
            if(!(--GL->adjList[k].in))
                stack[top++] = k;
        }
    }

    if(count != GL->numVertexes)
        return ERROR;
    else
        return OK;
}


int main(void)
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);

    TopologicalSort(&GL);


    return 0;
}