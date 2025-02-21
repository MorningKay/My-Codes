#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

#define Type int

typedef struct AVLNode
{
    Type data;
    AVLNode *leftChild;
    AVLNode *rightChild;
    int bf;
}AVLNode;

typedef struct AVLTree
{
    AVLNode *root;
}AVLTree;

void InitAVLTree(AVLTree *avl);
AVLNode *buyNode(Type x);

bool InsertAVL(AVLTree *avl, Type x);
bool InsertAVL(AVLNode *&t, Type x);

bool RemoveAVL(AVLTree *avl, Type key);
bool RemoveAVL(AVLNode *&t, Type key);

void RotateR(AVLNode *&ptr);
void RotateL(AVLNode *&ptr);
void RotateLR(AVLNode *&ptr);
void RotateRL(AVLNode *&ptr);

#endif //__AVLTREE_H__