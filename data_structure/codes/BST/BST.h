#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define T int

typedef struct BSTNode
{
    T data;
    BSTNode *leftChild;
    BSTNode *rightChild;
}BSTNode;

typedef struct BST
{
    BSTNode *root;
}BST;

void InitBSTree(BST *bst);

bool InsertBSTree(BST *bst, T x);
bool InsertBSTree(BSTNode **t, T x);

T min(BST *bst);
T min(BSTNode *t);

T max(BST *bst);
T max(BSTNode *t);

void sort(BST *bst);
void sort(BSTNode *t);

BSTNode *search(BST *bst, T key);
BSTNode *search(BSTNode *t, T key);

bool RemoveBSTree(BST *bst, T key);
bool RemoveBSTree(BSTNode **t, T key);

void MakeEmptyBSTree(BST *bst);
void MakeEmptyBSTree(BSTNode **t);