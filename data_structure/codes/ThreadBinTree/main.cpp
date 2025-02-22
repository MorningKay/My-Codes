#include "ThreadBinTree.h"

int main()
{
    char *str = "ABC##DE##F##G#H##";
    BinTree mytree;
    InitBinTree(&mytree, '#');
    CreateBinTree(&mytree, str);

    CreateInThread(&mytree);

    BinTreeNode *p1 = First(&mytree);
    printf("The first data is: %c\n", p1->data); // C

    BinTreeNode *p2 = Last(&mytree);
    printf("The last data is: %c\n", p2->data); // H

    InOrder(&mytree);

    BinTreeNode *p3 = Search(&mytree, 'D');
    BinTreeNode *q1 = Next(&mytree, p3);
    BinTreeNode *q2 = Prior(&mytree, p3);
    printf("D's next data is: %c\n", q1->data);
    printf("D's prior data is: %c\n", q2->data);

    BinTreeNode *p4 = Search(&mytree, 'E');
    BinTreeNode *parent = Parent(&mytree, p4);
    printf("E's parent data is: %c\n", parent->data);
}