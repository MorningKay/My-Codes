#include "Tree.h"

int main()
{
    char *str = "RAD#E##B#CFG#H#K#####";
    // 树：
    //       R
    //     / | \
    //    A  B  C
    //   / \    |
    //  D   E   F
    //        / | \
    //       G  H  K
    
    // 对应二叉树
    //      R
    //     /
    //    A
    //   / \
    //  D   B
    //   \   \
    //    E   C
    //       /
    //      F
    //     /
    //    G
    //     \
    //      H
    //       \
    //        K
    Tree tree;
    InitTree(&tree, '#');
    CreateTree(&tree, str);

    TreeNode *r = Root(&tree);
    printf("The tree's root is %c.\n", r->data);

    TreeNode *p = Find(&tree, 'B');
    TreeNode *parent = Parent(&tree, p);
    printf("%c's parent is %c.\n", p->data, parent->data);
}