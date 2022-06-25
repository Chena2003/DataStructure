/**
 * @file graph8.cpp
 * @author Chena
 * @brief 
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


int *etv, *ltv;
int *stack2;
int top2;


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
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j]=INF;
        }
    }

    
	G->arc[0][1]=3;
	G->arc[0][2]=4; 
	G->arc[1][3]=5; 
	G->arc[1][4]=6; 
	G->arc[2][3]=8; 
	G->arc[2][5]=7; 
	G->arc[3][4]=3;
	G->arc[4][6]=9; 
	G->arc[4][7]=4;
	G->arc[5][7]=6; 
	G->arc[6][9]=2;
	G->arc[7][8]=5;
	G->arc[8][9]=3;
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
            if(G.arc[i][j]!=0 && G.arc[i][j]<INF)
            {
                e = (EdgeNode * )malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->weight = G.arc[i][j];
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
    int *stack = (int *)malloc(GL->numVertexes * sizeof(int));
    int top = 0;
    int count = 0;

    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

    for(i = 0; i < GL->numVertexes; ++i)
        etv[i] = 0;
        if(GL->adjList[i].in == 0)
            stack[top++] = i;

    while(top != 0)
    {
        gettop = stack[--top];
        count++;
        stack2[top2++] = gettop;

        for(e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(!(--GL->adjList[k].in))
                stack[top++] = k;
            
            if((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }

    if(count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}


void CriticalPath(GraphAdjList *GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;

    int re = TopologicalSort(GL);
    printf("%d", re);

    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0; i < GL->numVertexes; ++i)
        ltv[i] = etv[GL->numVertexes - 1];

    while(top2 != 0)
    {
        gettop = stack2[--top2];
        for(e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }

        for(j = 0; j < GL->numVertexes; ++j)
        {
            for(e = GL->adjList[j].firstedge; e; e = e->next)
            {
                k = e->adjvex;
                ete = etv[j];
                lte = ltv[k] - e->weight;
                if(ete == lte)
                    printf("<v%d, v%d> length: %d,",
                            GL->adjList[j].data, GL->adjList[k].data,e->weight);
            }
        }
    }
}

int main(void)
{
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);

    CriticalPath(&GL);

    return 0;
}