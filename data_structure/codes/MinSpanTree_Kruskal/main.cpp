#include "MinSpanTree_Kruskal.h"

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

    InsertEdge(&gm, 'A', 'B', 6);
    InsertEdge(&gm, 'A', 'C', 1);
    InsertEdge(&gm, 'A', 'D', 5);
    InsertEdge(&gm, 'B', 'C', 5);
    InsertEdge(&gm, 'B', 'E', 3);
    InsertEdge(&gm, 'C', 'D', 5);
    InsertEdge(&gm, 'C', 'E', 6);
    InsertEdge(&gm, 'C', 'F', 4);
    InsertEdge(&gm, 'D', 'F', 2);
    InsertEdge(&gm, 'E', 'F', 6);
    ShowGraph(&gm);
    printf("\n");

    MinSpanTree_Kruskal(&gm);

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