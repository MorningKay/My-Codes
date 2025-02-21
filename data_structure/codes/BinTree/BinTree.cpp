#include "BinTree.h"
#include "LinkQueue.h"
#include "SeqStack.h"

void InitBinTree(BinTree *bt, ElemType ref)
{
    bt->root = NULL;
    bt->refvalue = ref;
}

// 以下为创建二叉树的四种方法，第二种与第四种只能用cpp实现
void CreateBinTree_1(BinTree *bt)
{
    CreateBinTree_1(bt, &(bt->root));
}
void CreateBinTree_1(BinTree *bt, BinTreeNode **t) // .c文件不能函数重载，.cpp可以
{
    ElemType Item;
    scanf("%c", &Item);
    if (Item == bt->refvalue)
    {
        (*t) = NULL;
    }
    else
    {
        (*t) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert((*t) != NULL);
        (*t)->data = Item;
        CreateBinTree_1(bt, &((*t)->leftChild));
        CreateBinTree_1(bt, &((*t)->rightChild));
    }
}

void CreateBinTree_2(BinTree *bt) // .cpp可用
{
    CreateBinTree_2(bt, bt->root);
}
void CreateBinTree_2(BinTree *bt, BinTreeNode *&t)
{
    ElemType Item;
    scanf("%c", &Item);
    if (Item == bt->refvalue)
    {
        t = NULL;
    }
    else
    {
        t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t != NULL);
        t->data = Item;
        CreateBinTree_2(bt, t->leftChild);
        CreateBinTree_2(bt, t->rightChild);
    }
}

void CreateBinTree_3(BinTree *bt)
{
    bt->root = CreateBinTree_3_(bt);
}
BinTreeNode* CreateBinTree_3_(BinTree *bt)
{
    ElemType Item;
    scanf("%c", &Item);
    if (Item == bt->refvalue)
    {
        return NULL;
    }
    else
    {
        BinTreeNode *t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t != NULL);
        t->data = Item;
        t->leftChild = CreateBinTree_3_(bt);
        t->rightChild = CreateBinTree_3_(bt);
        return t;
    }
}

void CreateBinTree_4(BinTree *bt, char *str) // .cpp可用
{
    CreateBinTree_4(bt, bt->root, str);
}
void CreateBinTree_4(BinTree *bt, BinTreeNode *&t, char *&str)
{
    if (*str == bt->refvalue)
    {
        t = NULL;
    }
    else
    {
        t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t != NULL);
        t->data = *str;
        CreateBinTree_4(bt, t->leftChild, ++str);
        CreateBinTree_4(bt, t->rightChild, ++str);
    }
}

///////////////////////////////////////////
void PreOrder(BinTree *bt)
{
    PreOrder(bt->root);
}
void PreOrder(BinTreeNode *t)
{
    if (t != NULL)
    {
        printf("%c ", t->data);
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}

void InOrder(BinTree *bt)
{
    InOrder(bt->root);
}
void InOrder(BinTreeNode *t)
{
    if (t != NULL)
    {
        InOrder(t->leftChild);
        printf("%c ", t->data);
        InOrder(t->rightChild);

    }
}

void PostOrder(BinTree *bt)
{
    PostOrder(bt->root);
}
void PostOrder(BinTreeNode *t)
{
    if (t != NULL)
    {
        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        printf("%c ", t->data);
    }
}

void LevelOrder(BinTree *bt)
{
    LevelOrder(bt->root);
}
void LevelOrder(BinTreeNode *t)
{
    if (t != NULL)
    {
        BinTreeNode *v;
        LinkQueue Q;
        InitQueue(&Q);
        EnQueue(&Q, t);

        while (!QueueIsEmpty(&Q))
        {
            GetHead(&Q, &v);
            DeQueue(&Q);
            printf("%c ", v->data);
            if (v->leftChild != NULL)
            {
                EnQueue(&Q, v->leftChild);
            }
            if (v->rightChild != NULL)
            {
                EnQueue(&Q, v->rightChild);
            }
        }
    }
}

///////////////////////////////////////////
int size(BinTree *bt)
{
    return size(bt->root);
}
int size(BinTreeNode *t)
{
    if (t == NULL)
        return 0;
    else
        return size(t->leftChild) + size(t->rightChild) + 1;
}

int height(BinTree *bt)
{
    return height(bt->root);
}
int height(BinTreeNode *t)
{
    if (t == NULL)
        return 0;
    else
    {
        int left_height = height(t->leftChild);
        int right_height = height(t->rightChild);
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

BinTreeNode *search(BinTree *bt, ElemType key)
{
    return search(bt->root, key);
}
BinTreeNode *search(BinTreeNode *t, ElemType key)
{
    if (t == NULL)
        return NULL;
    if (t->data == key)
        return t;

    BinTreeNode *p = search(t->leftChild, key);
    if (p != NULL)
        return p;
    return search(t->rightChild, key);
}

BinTreeNode *parent(BinTree *bt, BinTreeNode *p)
{
    return parent(bt->root, p);
}
BinTreeNode *parent(BinTreeNode *t, BinTreeNode *p)
{
    if (t == NULL || p == NULL)
        return NULL;
    if (t->leftChild == p || t->rightChild == p)
        return t;
    
    BinTreeNode *q = parent(t->leftChild, p);
    if (q != NULL)
        return q;
    return parent(t->rightChild, p);
}

BinTreeNode *LeftChild(BinTreeNode *p)
{
    if (p != NULL)
        return p->leftChild;
    return NULL;
}
BinTreeNode *RightChild(BinTreeNode *p)
{
    if (p != NULL)
        return p->rightChild;
    return NULL;
}

bool BinTree_is_empty(BinTree *bt)
{
    return bt->root == NULL;
}

void copy(BinTree *bt1, BinTree *bt2)
{
    copy(bt1->root, bt2->root);
}
void copy(BinTreeNode *&t1, BinTreeNode *t2)
{
    if (t2 == NULL)
        t1 = NULL;
    else
    {
        t1 = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t1 != NULL);
        t1->data = t2->data;
        copy(t1->leftChild, t2->leftChild);
        copy(t1->rightChild, t2->rightChild);
    }
}

void clear(BinTree *bt)
{
    clear(bt->root);
}
void clear(BinTreeNode *&t)
{
    if (t != NULL)
    {
        clear(t->leftChild);
        clear(t->rightChild);
        free(t);
        t = NULL;
    }
}

///////////////////////////////////////////
void PreOrder_1(BinTree *bt)
{
    PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode *t)
{
    if (t != NULL)
    {
        SeqStack st;
        InitStack(&st);
        BinTreeNode *p;
        Push(&st, t);
        while (!IsEmpty(&st))
        {
            GetTop(&st, &p);
            Pop(&st);
            printf("%c ", p->data);
            if (p->rightChild != NULL)
                Push(&st, p->rightChild);
            if (p->leftChild != NULL)
                Push(&st, p->leftChild);
        }
    }
}

void InOrder_1(BinTree *bt)
{
    InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode *t)
{
    if (t != NULL)
    {
        SeqStack st;
        InitStack(&st);
        BinTreeNode *p;
        Push(&st, t);
        while (!IsEmpty(&st))
        {
            while (t != NULL && t->leftChild != NULL)
            {
                Push(&st, t->leftChild);
                t = t->leftChild;
            }

            GetTop(&st, &p);
            Pop(&st);
            printf("%c ", p->data);

            if (p->rightChild != NULL)
            {
                t = p->rightChild;
                if (t != NULL)
                    Push(&st, t);
            }
        }
    }
}

// void PostOrder_1(BinTree *bt);
// void PostOrder_1(BinTreeNode *t); // 暂时搁置非递归实现方法

///////////////////////////////////////////
void CreateBinTree_5(BinTree *bt, char *VLR, char *LVR, int n)
{
    CreateBinTree_5(bt->root, VLR, LVR, n);
}
void CreateBinTree_5(BinTreeNode *&t, char *VLR, char *LVR, int n)
{
    if (n == 0)
    {
        t = NULL;
    }
    else
    {
        int k = 0;
        while (VLR[0] != LVR[k])
        {
            k++;
        }

        t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t != NULL);
        t->data = LVR[k];

        CreateBinTree_5(t->leftChild, VLR + 1, LVR, k);
        CreateBinTree_5(t->rightChild, VLR + k + 1, LVR + k + 1, n - k - 1);
    }
}

void CreateBinTree_6(BinTree *bt, char *LVR, char *LRV, int n)
{
    CreateBinTree_6(bt->root, LVR, LRV, n);
}
void CreateBinTree_6(BinTreeNode *&t, char *LVR, char *LRV, int n)
{
    if (n == 0)
    {
        t = NULL;
    }
    else
    {
        int k = 0;
        while (LRV[n-1] != LVR[k])
        {
            k++;
        }

        t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        assert(t != NULL);
        t->data = LVR[k];

        CreateBinTree_6(t->rightChild, LVR + k + 1, LRV + k, n - k - 1);
        CreateBinTree_6(t->leftChild, LVR, LRV, k);
    }
}