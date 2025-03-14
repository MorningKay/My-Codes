#include "GraphMtx.h"

int main()
{
    GraphMtx gm;
    // GraphMtx *g = &gm;
    InitGraph(&gm);
    InsertVertex(&gm, 'A');
    InsertVertex(&gm, 'B');
    InsertVertex(&gm, 'C');
    InsertVertex(&gm, 'D');
    InsertVertex(&gm, 'E');
    InsertVertex(&gm, 'F');
    InsertVertex(&gm, 'G');
    InsertVertex(&gm, 'H');
    InsertVertex(&gm, 'I');

    InsertEdge(&gm, 'A', 'B', 6);
    InsertEdge(&gm, 'A', 'C', 4);
    InsertEdge(&gm, 'A', 'D', 5);
    InsertEdge(&gm, 'B', 'E', 1);
    InsertEdge(&gm, 'C', 'E', 1);
    InsertEdge(&gm, 'D', 'F', 2);
    InsertEdge(&gm, 'E', 'G', 9);
    InsertEdge(&gm, 'E', 'H', 7);
    InsertEdge(&gm, 'F', 'H', 4);
    InsertEdge(&gm, 'G', 'I', 2);
    InsertEdge(&gm, 'H', 'I', 6);

    ShowGraph(&gm);
    printf("\n");

    CriticalPath(&gm);

    // RemoveEdge(&gm, 'B', 'C');
    // ShowGraph(&gm);
    // printf("\n");

    // RemoveVertex(&gm, 'C');
    // ShowGraph(&gm);

    DestoryGraph(&gm);

    // int p1 = GetFirstNeighbor(&gm, 'A');
    // printf("A's first neighbor is %c.\n", g->VerticesList[p1]);

    // int p2 = GetNextNeighbor(&gm, 'C', 'B');
    // printf("The next neighbor of C's neighbor B is %c.\n", g->VerticesList[p2]);
}