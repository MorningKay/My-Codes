#include "MinSpanTree_Prim.h"

void InitGraph(GraphMtx *g)
{
    g->MaxVertices = Default_Vertex_Size;
    g->NumVertices = g->NumEdges = 0;

    g->VerticesList = (T *)malloc(sizeof(T) * (g->MaxVertices));
    assert(g->VerticesList != NULL);

    // 二维数组的空间开辟
    g->Edge = (int **)malloc(sizeof(int *) * (g->MaxVertices));
    assert(g->Edge != NULL);
    for (int i = 0; i < g->MaxVertices; ++i)
    {
        g->Edge[i] = (int *)malloc(sizeof(int) * g->MaxVertices);
    }

    for (int i = 0; i < g->MaxVertices; ++i)
    {
        for (int j = 0; j < g->MaxVertices; ++j)
        {
            if (i == j)
            {
                g->Edge[i][j] = 0;
            }
            else
            {
                g->Edge[i][j] = MAX_COST;
            }
        }
    }
}

int GetVertexPos(GraphMtx *g, T v)
{
    for (int i = 0; i < g->NumVertices; ++i)
    {
        if (g->VerticesList[i] == v)
            return i;
    }
    return -1;
}

void ShowGraph(GraphMtx *g)
{
    printf("  ");
    for (int i = 0; i < g->NumVertices; ++i)
    {
        printf("%c ", g->VerticesList[i]);
    }
    printf("\n");
    for (int i = 0; i < g->NumVertices; ++i)
    {
        printf("%c ", g->VerticesList[i]);
        for (int j = 0; j < g->NumVertices; ++j)
        {
            if (g->Edge[i][j] == MAX_COST)
            {
                printf("%c ", '@');
            }
            else
            {
                printf("%d ", g->Edge[i][j]);
            }
        }
        printf("\n");
    }
}  

void InsertVertex(GraphMtx *g, T v)
{
    if (g->NumVertices >= g->MaxVertices)
        return;
    g->VerticesList[g->NumVertices++] = v;
}

void InsertEdge(GraphMtx *g, T v1, T v2, E cost)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);
    if (p1 == -1 || p2 == -1)
        return;
    
    g->Edge[p1][p2] = g->Edge[p2][p1] = cost;
    g->NumEdges++;
}

void RemoveEdge(GraphMtx *g, T v1, T v2)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);
    if (p1 == -1 || p2 == -1)
        return;

    if (g->Edge[p1][p2] == 0 || g->Edge[p2][p1] == 0)
        return;
    
    g->Edge[p1][p2] = g->Edge[p2][p1] = 0;
    g->NumEdges--;
}

void RemoveVertex(GraphMtx *g, T v)
{
    int p = GetVertexPos(g, v);
    if (p == -1)
        return;

    int numedges = 0;

    for (int i = p; i < g->NumVertices - 1; ++i)
    {
        g->VerticesList[i] = g->VerticesList[i + 1];
    }

    for (int i = 0; i < g->NumVertices; ++i)
    {
        if (g->Edge[p][i] != 0)
        {
            numedges++;
        }
    }

    for (int i = p; i < g->NumVertices - 1; ++i)
    {
        for (int j = 0; j < g->NumVertices; ++j)
        {
            g->Edge[i][j] = g->Edge[i + 1][j];
        }
    }

    for (int i = p; i < g->NumVertices; ++i)
    {
        for (int j = 0; j < g->NumVertices; ++j)
        {
            g->Edge[j][i] = g->Edge[j][i + 1];
        }
    }
    g->NumVertices--;
    g->NumEdges -= numedges;
}

void DestoryGraph(GraphMtx *g)
{
    free(g->VerticesList);
    g->VerticesList = NULL;
    for (int i = 0; i < g->NumVertices; ++i)
    {
        free(g->Edge[i]);
    }
    free(g->Edge);
    g->Edge = NULL;
    g->MaxVertices = g->NumEdges = g->NumVertices = 0;
}

int GetFirstNeighbor(GraphMtx *g, T v)
{
    int p = GetVertexPos(g, v);
    if (p == -1)
        return -1;
    
    for (int i = 0; i < g->NumVertices; ++i)
    {
        if (g->Edge[p][i] == 1)
            return i;
    }
    return -1;
}

int GetNextNeighbor(GraphMtx *g, T v, T w)
{
    int pv = GetVertexPos(g, v);
    int pw = GetVertexPos(g, w);
    if (pv == -1 || pw == -1)
        return -1;
    
    for (int i = pw + 1; i < g->NumVertices; ++i)
    {
        if (g->Edge[pv][i] == 1)
            return i;
    }
    return -1;
}

////////////////////////////////////////////////////
//
E GetWeight(GraphMtx *g, int v1, int v2)
{
    if (v1 == -1 || v2 == -1)
        return MAX_COST;
    return g->Edge[v1][v2];
}

void MinSpanTree_Prim(GraphMtx *g, T vertex)
{
    int n = g->NumVertices;
    E *lowcost = (E *)malloc(sizeof(E) * n); // lowcost[n]
    int *mst = (int *)malloc(sizeof(int) * n); // mst[n]
    assert(lowcost != NULL && mst != NULL);

    int k = GetVertexPos(g, vertex);

    for (int i = 0; i < n; ++i)
    {
        if (i != k)
        {
            lowcost[i] = GetWeight(g, k, i);
            mst[i] = k;
        }
        else
        {
            lowcost[i] = 0;
        }
    }

    int min, min_index;
    int begin, end;
    E cost;

    for (int i = 0; i < n - 1; ++i)
    {
        min = MAX_COST;
        min_index = -1;
        for (int j = 0; j < n; ++j)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                min_index = j;
            }
        }
        begin = mst[min_index];
        end = min_index;
        printf("%c-->%c : %d\n", g->VerticesList[begin], g->VerticesList[end], min);

        lowcost[min_index] = 0;

        for(int j = 0; j < n; ++j)
        {
            cost = GetWeight(g, min_index, j);
            if (cost < lowcost[j])
            {
                lowcost[j] = cost;
                mst[j] = min_index;
            }
        }
    }
}