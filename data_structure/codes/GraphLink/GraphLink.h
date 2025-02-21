#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define Default_Vertex_Size 10
#define T char

typedef struct Edge // 边
{
    int dest;
    struct Edge *link;
}Edge;

typedef struct Vertex // 顶点
{
    T data;
    Edge *adj;
}Vertex;

typedef struct GraphLink // 图
{
    int MaxVertices;
    int NumVertices;
    int NumEdges;

    Vertex *NodeTable;
}GraphLink;

void InitGraph(GraphLink *g);
int GetVertexPos(GraphLink *g, T v);
void ShowGraph(GraphLink *g);
void InsertVertex(GraphLink *g, T v);
void InsertEdge(GraphLink *g, T vertex1, T vertex2);

void RemoveEdge(GraphLink *g, T vertex1, T vertex2);
void RemoveVertex(GraphLink *g, T vertex);
void DestroyGraph(GraphLink *g);
int GetFirstNeighbor(GraphLink *g, T vertex);
int GetNextNeighbor(GraphLink *g, T vertex1, T vertex2);

void TopologicalSort(GraphLink *g);