#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ElemType int

#define MAXSIZE 8

typedef struct Queue
{
    ElemType *base;
    int front;
    int rear;
}Queue;

void InitQueue(Queue *Q);
void EnQueue(Queue *Q, ElemType x);
void ShowQueue(Queue *Q);
void DeQueue(Queue *Q);

void GetHead(Queue *Q, ElemType *v);
int length(Queue *Q);
void clear(Queue *Q);
void destroy(Queue *Q);

#endif //__SEQQUEUE_H__