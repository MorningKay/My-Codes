#include "BinTree.h"

int main()
{
    char *str = "ABC##DE##F##G#H##";
    //      A
    //     / \
    //    B   G
    //   / \   \
    //  C   D   H
    //     / \
    //    E   F 
    BinTree mytree;
    InitBinTree(&mytree, '#');

    CreateBinTree_4(&mytree, str);

    // 递归方法
    PreOrder(&mytree); // A B C D E F G H
    printf("\n");

    InOrder(&mytree); // C B E D F A G H
    printf("\n");

    PostOrder(&mytree); // C E F D B H G A
    printf("\n");

    // LevelOrder(&mytree); // C E F D B H G A
    // printf("\n");

    // printf("BinTree's size is %d.\n", size(&mytree)); // 8
    // printf("BinTree's height is %d\n", height(&mytree)); // 4

    // BinTreeNode *p = search(&mytree, 'B');
    // printf("can find the data: %c\n", p->data); // B

    // BinTreeNode *p_parent = parent(&mytree, p);
    // printf("%c's parent is %c.\n", p->data, p_parent->data);

    // BinTreeNode *p_leftchild = LeftChild(p);
    // BinTreeNode *p_rightchild = RightChild(p);
    // printf("%c's leftchild is %c, rightchild is %c\n", p->data, p_leftchild->data, p_rightchild->data);

    // BinTree youtree;
    // InitBinTree(&youtree, '#');
    // copy(&youtree, &mytree);
    // printf("\n");
    // PreOrder(&youtree);
    // printf("\n");

    // clear(&youtree);
    // PreOrder(&youtree);
    // printf("\n");
    
    
    // 非递归方法
    // PreOrder_1(&mytree);
    // printf("\n");

    InOrder_1(&mytree);
    printf("\n");

    // 后序较难实现，暂搁置

    // 二叉树恢复实现
    // char *VLR = "ABCDEFGH";
    // char *LVR = "CBEDFAGH";
    // char *LRV = "CEFDBHGA";
    // char *VLR = "ABDFCEGH";
    // char *LVR = "BFDAGEHC";

    // int n = strlen(VLR);

    // BinTree mytree;
    // InitBinTree(&mytree, '#');

    // CreateBinTree_5(&mytree, VLR, LVR, n);

    // BinTree youtree;
    // InitBinTree(&youtree, '#');

    // CreateBinTree_6(&youtree, LVR, LRV, n);
}