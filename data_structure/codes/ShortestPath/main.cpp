#include "ShortestPath.h"

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

    InsertEdge(&gm, 'A', 'B', 10);
    InsertEdge(&gm, 'A', 'D', 30);
    InsertEdge(&gm, 'A', 'E', 100);
    InsertEdge(&gm, 'B', 'C', 50);
    InsertEdge(&gm, 'C', 'E', 10);
    InsertEdge(&gm, 'D', 'C', 20);
    InsertEdge(&gm, 'D', 'E', 60);
    ShowGraph(&gm);
    printf("\n");

    int n = gm.NumVertices;
    //
    E *dist = (E *)malloc(sizeof(E) * n);
    int *path = (int *)malloc(sizeof(int) * n);
    assert(dist != NULL && path != NULL);

    ShortestPath(&gm, 'A', dist, path);

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