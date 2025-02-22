#include "GraphLink.h"

int main()
{
    GraphLink gl;
    InitGraph(&gl);
    InsertVertex(&gl, 'A');
    InsertVertex(&gl, 'B');
    InsertVertex(&gl, 'C');
    InsertVertex(&gl, 'D');
    InsertVertex(&gl, 'E');
    InsertVertex(&gl, 'F');

    InsertEdge(&gl, 'A', 'B');
    InsertEdge(&gl, 'A', 'C');
    InsertEdge(&gl, 'A', 'D');
    InsertEdge(&gl, 'C', 'B');
    InsertEdge(&gl, 'C', 'E');
    InsertEdge(&gl, 'D', 'E');
    InsertEdge(&gl, 'F', 'D');
    InsertEdge(&gl, 'F', 'E');
    ShowGraph(&gl);

    TopologicalSort(&gl);
    printf("\n");

    // RemoveEdge(&gl, 'B', 'C');
    // RemoveVertex(&gl, 'C');
    // ShowGraph(&gl);

    // int v = GetFirstNeighbor(&gl, 'A');
    // int v = GetNextNeighbor(&gl, 'B', 'A');
    // printf("%d\n", v);

    DestroyGraph(&gl);
}