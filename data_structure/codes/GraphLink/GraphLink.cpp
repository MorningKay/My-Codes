#include "GraphLink.h"

void InitGraph(GraphLink *g)
{
    g->MaxVertices = Default_Vertex_Size;
    g->NumEdges = g->NumVertices = 0;

    g->NodeTable = (Vertex *)malloc(sizeof(Vertex) * g->MaxVertices);
    assert(g->NodeTable != NULL);
    for (int i = 0; i < g->MaxVertices; ++i)
    {
        g->NodeTable[i].adj = NULL;
    }
}

int GetVertexPos(GraphLink *g, T v)
{
    for (int i = 0; i < g->NumVertices; ++i)
    {
        if (g->NodeTable[i].data == v)
            return i;
    }
    return -1;
}

void ShowGraph(GraphLink *g)
{
    Edge *p;
    for (int i = 0; i < g->NumVertices; ++i)
    {
        printf("%d %c:>", i, g->NodeTable[i].data);
        p = g->NodeTable[i].adj;
        while (p != NULL)
        {
            printf("%d-->", p->dest);
            p = p->link;
        }
        printf("Nul.\n");
    }
    printf("\n");
}

void InsertVertex(GraphLink *g, T v)
{
    if (g->NumVertices >= g->MaxVertices)
        return;
    g->NodeTable[g->NumVertices++].data = v;
}

void InsertEdge(GraphLink *g, T vertex1, T vertex2)
{
    int v1 = GetVertexPos(g, vertex1);
    int v2 = GetVertexPos(g, vertex2);
    if (v1 == -1 || v2 == -1)
        return;
    
    Edge *s;
    // v1 --> v2
    s = (Edge *)malloc(sizeof(Edge));
    assert(s != NULL);
    s->dest = v2;
    s->link = g->NodeTable[v1].adj;
    g->NodeTable[v1].adj = s;

    // v2 --> v1 若生成有向图，则注释下列代码
    // s = (Edge *)malloc(sizeof(Edge));
    // assert(s != NULL);
    // s->dest = v1;
    // s->link = g->NodeTable[v2].adj;
    // g->NodeTable[v2].adj = s;

    g->NumEdges++;
}

void RemoveEdge(GraphLink *g, T vertex1, T vertex2)
{
    int v1 = GetVertexPos(g, vertex1);
    int v2 = GetVertexPos(g, vertex2);

    if (v1 == -1 || v2 == -1)
        return;
    
    Edge *q = NULL;
    Edge *p;
    // v1 --> v2
    p = g->NodeTable[v1].adj;
    while (p != NULL && p->dest != v2)
    {
        q = p;
        p = p->link;
    }
    if (p == NULL)
        return;

    if (q == NULL)
    {
        g->NodeTable[v1].adj = p->link;
    }
    else
    {
        q->link = p->link;
    }
    free(p);

    // v2 --> v1
    q = NULL;
    p = g->NodeTable[v2].adj;
    while (p->dest != v1)
    {
        q = p;
        p = p->link;
    }
    if (q == NULL)
    {
        g->NodeTable[v2].adj = p->link;
    }
    else
    {
        q->link = p->link;
    }
    free(p);
    g->NumEdges--;
}

void RemoveVertex(GraphLink *g, T vertex)
{
    int v = GetVertexPos(g, vertex);
    if (v == -1)
        return;
    
    Edge *p = g->NodeTable[v].adj;

    int k;
    Edge *t = NULL;
    Edge *s;
    while (p != NULL)
    {
        k = p->dest;
        s = g->NodeTable[k].adj;
        while (s != NULL && s->dest != v)
        {
            t = s;
            s = s->link;
        }
        if (s != NULL)
        {
            if (t == NULL)
            {
                g->NodeTable[k].adj = s->link;
            }
            else
            {
                t->link = s->link;
            }
            free(s);
        }

        g->NodeTable[v].adj = p->link;
        free(p);
        p = g->NodeTable[v].adj;
    }

    g->NumVertices--;
    g->NodeTable[v].data = g->NodeTable[g->NumVertices].data;
    g->NodeTable[v].adj = g->NodeTable[g->NumVertices].adj;

    s = g->NodeTable[v].adj;
    while (s != NULL)
    {
        k = s->dest;
        p = g->NodeTable[k].adj;
        while (p != NULL)
        {
            if (p->dest == g->NumVertices)
            {
                p->dest = v;
                break;
            }
            p = p->link;
        }
        s = s->link;
    }
}

void DestroyGraph(GraphLink *g)
{
    Edge *p;
    for (int i = 0; i < g->NumVertices; ++i)
    {
        p = g->NodeTable[i].adj;
        while (p != NULL)
        {
            g->NodeTable[i].adj = p->link;
            free(p);
            p = g->NodeTable[i].adj;
        }
    }
    free(g->NodeTable);
    g->NodeTable = NULL;
    g->MaxVertices = g->NumEdges = g->NumVertices = 0;
}

int GetFirstNeighbor(GraphLink *g, T vertex)
{
    int v = GetVertexPos(g, vertex);
    if (v == -1)
        return -1;
    Edge *p = g->NodeTable[v].adj;
    if (p != NULL)
        return p->dest;
    return -1;
}

int GetNextNeighbor(GraphLink *g, T vertex1, T vertex2)
{
    int v1 = GetVertexPos(g, vertex1);
    int v2 = GetVertexPos(g, vertex2);
    if (v1 == -1 || v2 == -1)
        return -1;
    
    Edge *p = g->NodeTable[v1].adj;
    while (p != NULL && p->dest != v2)
        p = p->link;
    if (p != NULL && p->link != NULL)
        return p->link->dest;
    return -1;
}

void TopologicalSort(GraphLink *g)
{
    int n = g->NumVertices;
    int *count = (int *)malloc(sizeof(int) * n);
    assert(count != NULL);
    for (int i = 0; i < n; ++i)
    {
        count[i] = 0;
    }
    
    Edge *p;
    for (int i = 0; i < n; ++i)
    {
        p = g->NodeTable[i].adj;
        while (p != NULL)
        {
            count[p->dest]++;
            p = p->link;
        }
    }

    int top = -1;
    for (int i = 0; i < n; ++i)
    {
        if (count[i] == 0)
        {
            count[i] = top; // push
            top = i;
        }
    }

    int v, w;
    for (int i = 0; i < n; ++i)
    {
        if (top == -1)
        {
            printf("网络中有回路.\n");
            return;
        }
        else
        {
            v = top; // pop
            top = count[top];
            printf("%c-->", g->NodeTable[v].data);
            w = GetFirstNeighbor(g, g->NodeTable[v].data);
            while (w != -1)
            {
                if (--count[w] == 0)
                {
                    count[w] = top; // push
                    top = w;
                }
                w = GetNextNeighbor(g, g->NodeTable[v].data, g->NodeTable[w].data);
            }
        }
    }
    free(count);
}