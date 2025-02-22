#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define ElemType char

typedef struct BinTreeNode
{
    ElemType data;
    struct BinTreeNode *leftChild;
    struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
    BinTreeNode *root;
    ElemType refvalue; //stop flag
}BinTree;

void InitBinTree(BinTree *bt, ElemType ref);

///////////////////////////////////////////
//1
void CreateBinTree_1(BinTree *bt);
void CreateBinTree_1(BinTree *bt, BinTreeNode **t);

void CreateBinTree_2(BinTree *bt);
void CreateBinTree_2(BinTree *bt, BinTreeNode *&t);

void CreateBinTree_3(BinTree *bt);
BinTreeNode* CreateBinTree_3_(BinTree *bt);

void CreateBinTree_4(BinTree *bt, char *str);
void CreateBinTree_4(BinTree *bt, BinTreeNode *&t, char *&str);

///////////////////////////////////////////
//2 递归遍历
// 先序 V L R
// 中序 L V R
// 后序 L R V
// 层次 按层次来
void PreOrder(BinTree *bt);
void PreOrder(BinTreeNode *t);

void InOrder(BinTree *bt);
void InOrder(BinTreeNode *t);

void PostOrder(BinTree *bt);
void PostOrder(BinTreeNode *t);

void LevelOrder(BinTree *bt);
void LevelOrder(BinTreeNode *t);

///////////////////////////////////////////
//3
int size(BinTree *bt);
int size(BinTreeNode *t);

int height(BinTree *bt);
int height(BinTreeNode *t);

BinTreeNode *search(BinTree *bt, ElemType key);
BinTreeNode *search(BinTreeNode *t, ElemType key);

BinTreeNode *parent(BinTree *bt, BinTreeNode *p);
BinTreeNode *parent(BinTreeNode *t, BinTreeNode *p);

BinTreeNode *LeftChild(BinTreeNode *p);
BinTreeNode *RightChild(BinTreeNode *p);

bool BinTree_is_empty(BinTree *bt);

void copy(BinTree *bt1, BinTree *bt2);
void copy(BinTreeNode *&t1, BinTreeNode *t2);

void clear(BinTree *bt);
void clear(BinTreeNode *&t);

///////////////////////////////////////////
//4 非递归遍历
void PreOrder_1(BinTree *bt);
void PreOrder_1(BinTreeNode *t);

void InOrder_1(BinTree *bt);
void InOrder_1(BinTreeNode *t);

void PostOrder_1(BinTree *bt);
void PostOrder_1(BinTreeNode *t);

///////////////////////////////////////////
//5
void CreateBinTree_5(BinTree *bt, char *VLR, char *LVR, int n); // 利用前序和中序恢复二叉树
void CreateBinTree_5(BinTreeNode *&t, char *VLR, char *LVR, int n);

void CreateBinTree_6(BinTree *bt, char *LVR, char *LRV, int n); // 利用中序和后序恢复二叉树
void CreateBinTree_6(BinTreeNode *&t, char *LVR, char *LRV, int n);

// 无法利用前序和后序恢复二叉树