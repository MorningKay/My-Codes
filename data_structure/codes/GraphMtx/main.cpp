#include "GraphMtx.h"

int main()
{
    GraphMtx gm;
    GraphMtx *g = &gm;
    InitGraph(&gm);
    InsertVertex(&gm, 'A');
    InsertVertex(&gm, 'B');
    InsertVertex(&gm, 'C');
    InsertVertex(&gm, 'D');
    InsertVertex(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');
    ShowGraph(&gm);
    printf("\n");

    // RemoveEdge(&gm, 'B', 'C');
    // ShowGraph(&gm);
    // printf("\n");

    // RemoveVertex(&gm, 'C');
    // ShowGraph(&gm);

    // DestoryGraph(&gm);

    int p1 = GetFirstNeighbor(&gm, 'A');
    printf("A's first neighbor is %c.\n", g->VerticesList[p1]);

    int p2 = GetNextNeighbor(&gm, 'C', 'B');
    printf("The next neighbor of C's neighbor B is %c.\n", g->VerticesList[p2]);
}