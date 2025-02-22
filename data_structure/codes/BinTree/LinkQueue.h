#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "BinTree.h"

struct BinTreeNode;

#define EType BinTreeNode *

typedef struct QueueNode
{
    EType data;
    struct QueueNode *next;
}QueueNode;

typedef struct LinkQueue
{
    QueueNode *front;
    QueueNode *tail;
}LinkQueue;

void InitQueue(LinkQueue *Q);
bool QueueIsEmpty(LinkQueue *Q);
void EnQueue(LinkQueue *Q, EType x);
void ShowQueue(LinkQueue *Q);
void DeQueue(LinkQueue *Q);
void GetHead(LinkQueue *Q, EType *v);
int length(LinkQueue *Q);
void clear(LinkQueue *Q);
void destroy(LinkQueue *Q);

/////////////////////////////////////////////
void InitQueue(LinkQueue *Q)
{
    QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
    assert(s != NULL);
    Q->front = Q->tail = s;
    Q->tail->next = NULL;
}

bool QueueIsEmpty(LinkQueue *Q)
{
    return Q->front == Q->tail;
}

void EnQueue(LinkQueue *Q, EType x)
{
    QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;

    Q->tail->next = s;
    Q->tail = s;
}

void ShowQueue(LinkQueue *Q)
{
    QueueNode *p = Q->front->next;
    printf("Front:>");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("<:Tail.\n");
}

void DeQueue(LinkQueue *Q)
{
    if (Q->front == Q->tail)
    {
        return;
    }
    
    QueueNode *p = Q->front->next;

    Q->front->next = p->next;
    free(p);

    if (p == Q->tail)
    {
        Q->tail = Q->front;
    }
}

void GetHead(LinkQueue *Q, EType *v)
{
    if (Q->front == Q->tail)
    {
        return;
    }
    QueueNode *p = Q->front->next;
    *v = p->data;
}

int length(LinkQueue *Q)
{
    int len = 0;
    QueueNode *p = Q->front->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void clear(LinkQueue *Q)
{
    if (Q->front == Q->tail)
    {
        return;
    }

    QueueNode *p = Q->front->next;
    while (p != NULL)
    {
        Q->front->next = p->next;
        free(p);
        p = Q->front->next;
    }
    Q->tail = Q->front;
}

void destroy(LinkQueue *Q)
{
    clear(Q);
    free(Q->front);
    Q->front = Q->tail = NULL;
}

#endif //__LINKQUEUE_H__