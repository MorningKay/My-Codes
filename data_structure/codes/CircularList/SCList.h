#ifndef __SCLIST_H__
#define __SCLIST_H__

#define ElemType int

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node, *PNode;

typedef struct List
{
	PNode first;
	PNode last;
	int size;
}List;

Node* _buynode(ElemType x);

void InitSCList(List* list);

void push_back(List* list, ElemType x);
void push_front(List* list, ElemType x);
void show_list(List* list);

void pop_back(List* list);
void pop_front(List* list);
void insert_val(List* list, ElemType x);
Node* find(List* list, ElemType key);
int length(List* list);
void delete_val(List* list, ElemType key);
void sort(List* list);
void reverse(List* list);
void clear(List* list);
void destroy(List* list);

#endif //__SCLIST_H__