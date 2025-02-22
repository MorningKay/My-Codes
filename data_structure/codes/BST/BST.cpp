#include "BST.h"

void InitBSTree(BST *bst)
{
    bst->root = NULL;
}

bool InsertBSTree(BST *bst, T x)
{
    return InsertBSTree(&bst->root, x);
}
bool InsertBSTree(BSTNode **t, T x)
{
    if (*t == NULL)
    {
        *t = (BSTNode *)malloc(sizeof(BSTNode));
        assert(*t != NULL);
        (*t)->data = x;
        (*t)->leftChild = NULL;
        (*t)->rightChild = NULL;
        return true;
    }
    else if (x < (*t)->data)
    {
        InsertBSTree(&(*t)->leftChild, x);
    }
    else if (x > (*t)->data)
    {
        InsertBSTree(&(*t)->rightChild, x);
    }
    return false;
}

T min(BST *bst)
{
    assert(bst->root != NULL);
    return min(bst->root);
}
T min(BSTNode *t)
{
    while (t->leftChild != NULL)
        t = t->leftChild;
    return t->data;
}

T max(BST *bst)
{
    assert(bst->root != NULL);
    return max(bst->root);
}
T max(BSTNode *t)
{
    while (t->rightChild != NULL)
        t = t->rightChild;
    return t->data;
}

void sort(BST *bst)
{
    sort(bst->root);
}
void sort(BSTNode *t)
{
    if (t != NULL)
    {
        sort(t->leftChild);
        printf("%d ", t->data);
        sort(t->rightChild);
    }
}

BSTNode *search(BST *bst, T key)
{
    return search(bst->root, key);
}
BSTNode *search(BSTNode *t, T key)
{
    if (t == NULL)
        return NULL;
    if (t->data == key)
        return t;
    if (key < t->data)
        return search(t->leftChild, key);
    else
        return search(t->rightChild, key);
}

void MakeEmptyBSTree(BST *bst)
{
    MakeEmptyBSTree(&bst->root);
}
void MakeEmptyBSTree(BSTNode **t)
{
    if (*t != NULL)
    {
        MakeEmptyBSTree(&(*t)->leftChild);
        MakeEmptyBSTree(&(*t)->rightChild);
        free(*t);
        *t = NULL;
    }
}

/*
bool RemoveBSTree(BST *bst, T key)
{
    return RemoveBSTree(&bst->root, key);
}
bool RemoveBSTree(BSTNode **t, T key)
{
    if (*t == NULL)
        return false;
    if (key < (*t)->data)
        RemoveBSTree(&(*t)->leftChild, key);
    else if (key > (*t)->data)
        RemoveBSTree(&(*t)->rightChild, key);
    else
    {
        BSTNode *p = NULL;
        if ((*t)->leftChild == NULL && (*t)->rightChild == NULL)
        {
            free(*t);
            *t = NULL;
        }
        else if ((*t)->leftChild != NULL && (*t)->rightChild == NULL)
        {
            p = *t;
            *t = (*t)->leftChild;
            free(p);
            p = NULL;
        }
        else if ((*t)->leftChild == NULL && (*t)->rightChild != NULL)
        {
            p = *t;
            *t = (*t)->rightChild;
            free(p);
            p = NULL;
        }
        else
        {
            p = (*t)->rightChild;
            while (p->leftChild != NULL)
                p = p->leftChild;
            (*t)->data = p->data;
            RemoveBSTree(&(*t)->rightChild, p->data);
        }
    }
    return true;
}
*/

bool RemoveBSTree(BST *bst, T key)
{
    return RemoveBSTree(&bst->root, key);
}
bool RemoveBSTree(BSTNode **t, T key)
{
    if (*t == NULL)
        return false;
    if (key < (*t)->data)
        RemoveBSTree(&(*t)->leftChild, key);
    else if (key > (*t)->data)
        RemoveBSTree(&(*t)->rightChild, key);
    else
    {
        BSTNode *p = NULL;
        if ((*t)->leftChild != NULL && (*t)->rightChild != NULL)
        {
            p = (*t)->rightChild;
            while (p->leftChild != NULL)
                p = p->leftChild;
            (*t)->data = p->data;
            RemoveBSTree(&(*t)->rightChild, p->data);
        }
        else // 至多有一个节点
        {
            p = *t;
            if ((*t)->leftChild == NULL)
                (*t) = (*t)->rightChild;
            else
                (*t) = (*t)->leftChild;
            free(p);
            p = NULL;
        }
    }
    return true;
}