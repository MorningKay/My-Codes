#include "BST.h"

int main()
{
    T ar[] = {45, 12, 53, 3, 37, 100, 24, 61, 90, 78};
    int n = sizeof(ar) / sizeof(int);
    BST bst;
    InitBSTree(&bst);

    for (int i = 0; i < n; ++i)
    {
        InsertBSTree(&bst, ar[i]);
    }

    T minimum = min(&bst);
    printf("The minimum value is: %d\n", minimum);

    T maximum = max(&bst);
    printf("The maximum value is: %d\n", maximum);

    BSTNode *p = search(&bst, 3);

    sort(&bst);
    printf("\n");
}