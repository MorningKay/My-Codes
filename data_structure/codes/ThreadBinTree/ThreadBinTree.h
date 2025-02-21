#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ElemType char

typedef enum{LINK, THREAD} Tag_Type;

typedef struct BinTreeNode
{
    ElemType data;
    struct BinTreeNode *leftChild;
    struct BinTreeNode *rightChild;
    Tag_Type ltag;
    Tag_Type rtag;
}BinTreeNode;

typedef struct BinTree
{
    BinTreeNode *root;
    ElemType refvalue; //stop value
}BinTree;

////////////////////////////////////////////
//1

BinTreeNode *_buynode(ElemType x);
void InitBinTree(BinTree *bt, ElemType ref);

void CreateBinTree(BinTree *bt, char *&str);
void CreateBinTree(BinTree *bt, BinTreeNode *&t, char *&str);

void CreateInThread(BinTree *bt);
void CreateInThread(BinTreeNode *&t, BinTreeNode *&pre);

////////////////////////////////////////////
//2

BinTreeNode *First(BinTree *bt);
BinTreeNode *First(BinTreeNode *t);

BinTreeNode *Last(BinTree *bt);
BinTreeNode *Last(BinTreeNode *t);

BinTreeNode *Next(BinTree *bt, BinTreeNode *cur);
BinTreeNode *Next(BinTreeNode *t, BinTreeNode *cur);

BinTreeNode *Prior(BinTree *bt, BinTreeNode *cur);
BinTreeNode *Prior(BinTreeNode *t, BinTreeNode *cur);

void InOrder(BinTree *bt);
void InOrder(BinTreeNode *t);

BinTreeNode *Search(BinTree *bt, ElemType key);
BinTreeNode *Search(BinTreeNode *t, ElemType key);

BinTreeNode *Parent(BinTree *bt, BinTreeNode *cur);
BinTreeNode *Parent(BinTreeNode *t, BinTreeNode *cur);