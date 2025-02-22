#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"

#define T int
#define MAXSIZE 20

typedef T SqList[MAXSIZE];

void Swap (T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Not use zero space
void InsertSort(SqList &L, int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (L[i] < L[i-1])
        {
            Swap(&L[i], &L[i - 1]);
            for (int j = i - 1; j > 0 && L[j] < L[j-1]; --j)
            {
                Swap(&L[j], &L[j-1]);
            }
        }
    }
}
*/

void InsertSort(SqList &L, int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (L[i] < L[i-1])
        {
            L[0] = L[i];
            L[i] = L[i-1];

            int j;
            for (j = i - 2; L[0] < L[j]; --j)
            {
                L[j+1] = L[j];
            }
            L[j+1] = L[0];
        }
    }
}

void BInsertSort(SqList &L, int n)
{
    for (int i = 2; i < n; ++i)
    {
        L[0] = L[i];
        int low = 1;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (L[0] >= L[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        for (int j = i; j > high + 1; --j)
        {
            L[j] = L[j-1];
        }
        L[high + 1] = L[0];
    }
}

void TWayInsertSort(SqList &L, int n)
{
    SqList TP;
    TP[0] = L[0];
    int head, tail;
    head = tail = 0;

    for (int i = 1; i < n; ++i)
    {
        if (L[i] < TP[head])
        {
            head = (head - 1 + n) % n;
            TP[head] = L[i];
        }
        else if (L[i] > TP[tail])
        {
            tail++;
            TP[tail] = L[i];
        }
        else
        {
            tail++;
            TP[tail] = TP[tail - 1];
            int j;
            for (j = tail - 1; L[i] < TP[(j-1+n) % n]; j = (j-1+n) % n)
            {
                TP[j] = TP[(j-1+n) % n];
            }
            TP[j] = L[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        L[i] = TP[head];
        head = (head + 1) % n;
    }
}

//////////////////////////////////////////////////
// 表插入排序
#define MAXVALUE 0x7fffffff
typedef struct SLNode
{
    T data;
    int link;
}SLNode;

typedef SLNode Table[MAXSIZE];

void TableInsertSort(Table &t, int n)
{
    t[0].link = 1;
    int p, q;
    for (int i = 2; i < n; ++i)
    {
        p = t[0].link;
        q = 0;
        while (p != 0 && t[p].data <= t[i].data)
        {
            q = p;
            p = t[p].link;
        }
        t[i].link = t[q].link;
        t[q].link = i;
    }
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 希尔排序
void ShellInsert(SqList &L, int n, int dk)
{
    for (int i = dk + 1; i < n; ++i)
    {
        if (L[i] < L[i - dk])
        {
            L[0] = L[i];
            int j;
            for (j = i - dk; j > 0 && L[0] < L[j]; j -= dk)
            {
                L[j + dk] = L[j];
            }
            L[j + dk] = L[0];
        }
    }
}

void ShellSort(SqList &L, int n, int delta[], int t)
{
    for (int k = 0; k < t; ++k)
    {
        ShellInsert(L, n, delta[k]);
    }
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 冒泡排序
void BubbleSort(SqList &L, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (L[j] > L[j + 1])
            {
                Swap(&L[j], &L[j + 1]);
            }
        }
    }
}
//////////////////////////////////////////////////
// 快速排序
int Partition(SqList &L, int low, int high)
{
    T pk = L[low];
    while (low < high)
    {
        while (low < high && L[high] >= pk)
            high--;
        L[low] = L[high];
        while (low < high && L[low] < pk)
            low++;
        L[high] = L[low];
    }
    L[low] = pk;
    return low;
}

void QuickSort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int pkloc = Partition(L, low, high);
        QuickSort(L, low, pkloc - 1);
        QuickSort(L, pkloc + 1, high);
    }
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 选择排序
int SelectMinKey(SqList &L, int k, int n)
{
    T minval = L[k];
    int pos = k;

    for (int i = k; i < n; ++i)
    {
        if (L[i] < minval)
        {
            minval = L[i];
            pos = i;
        }
    }
    return pos;
}

void SelectSort(SqList &L, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int j = SelectMinKey(L, i ,n);
        if (j != i)
        {
            Swap(&L[j], &L[i]);
        }
    }
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 树形选择排序
#define MAXVALUE 0x7fffffff

T GetValue(T e[], int n, int p)
{
    if (p >= n)
        return MAXVALUE;
    T value;
    if (p < n / 2)
    {
        value = e[e[p]];
    }
    else
    {
        value = e[p];
    }
    return value;
}

void Play (T e[], int n, int p)
{
    int left, right;
    T leftvalue, rightvalue;
    while (p >= 0)
    {
        left = 2 * p + 1;
        right = 2 * p + 2;
        leftvalue = GetValue(e, n, left);
        rightvalue = GetValue(e, n, right);
        if (leftvalue <= rightvalue)
        {
            if (left < n / 2)
            {
                e[p] = e[left];
            }
            else
            {
                e[p] = left;
            }
        }
        else
        {
            if (right < n / 2)
            {
                e[p] = e[right];
            }
            else
            {
                e[p] = right;
            }
        }
        --p;
    }
}

void Select(T e[], int n, int p)
{
    int i = p; // parent
    int j = 2 * p + 1; // leftChild
    T leftvalue, rightvalue;
    int flag = -1;
    while (flag && i >= 0)
    {
        leftvalue = GetValue(e, n, j);
        rightvalue  = GetValue(e, n, j + 1);
        if (leftvalue <= rightvalue)
        {
            if (j < n / 2)
            {
                e[i] = e[j];
            }
            else
            {
                e[i] = j;
            }
        }
        else
        {
            if (j + 1 < n / 2)
            {
                e[i] = e[j + 1];
            }
            else
            {
                e[i] = j + 1;
            }
        }
        if (i == 0)
            flag++;
        i = (i - 1) / 2;
        j = 2 * i + 1;
    }
}

void TreeSelectSort(SqList &L, int n)
{
    int size = 2 * n - 1;
    T *e = (T *)malloc(sizeof(T) * size);
    assert(e != NULL);
    int k = size / 2;
    int i;
    for (i = 0; i < n; ++i)
    {
        e[k++] = L[i];
    }

    int curpos = size / 2 - 1;
    Play(e, size, curpos);
    i = 0;
    L[i] = e[e[0]];

    e[e[0]] = MAXVALUE;

    for (i = 1; i < n; ++i)
    {
        curpos = (e[0] - 1) / 2;
        Select(e, size, curpos);
        L[i] = e[e[0]];
        e[e[0]] = MAXVALUE;
    }

    free(e);
    e = NULL;
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 堆排序
void siftDown(T heap[], int n, int p)
{
    int i = p;
    int j = 2 * i + 1;
    while (j < n)
    {
        if (j < n - 1 && heap[j] > heap[j + 1])
            j++;
        if (heap[i] <= heap[j])
            break;
        else
        {
            Swap(&heap[i], &heap[j]);
            i = j;
            j = 2 * i + 1;
        }
    }
}

T RemoveMinKey(T heap[], int n)
{
    T key = heap[0];
    heap[0] = heap[n];
    siftDown(heap, n, 0);
    return key;
}

void HeapSort(SqList &L, int n)
{
    T *heap = (T *)malloc(sizeof(T) * n);
    assert(heap != NULL);
    for (int i = 0; i < n; ++i)
    {
        heap[i] = L[i];
    }
    int curpos = n / 2 - 1;
    while (curpos >= 0)
    {
        siftDown(heap, n, curpos);
        curpos--;
    }

    for (int i = 0; i < n; ++i)
    {
        L[i] = RemoveMinKey(heap, n-i-1); 
    }

    free(heap);
    heap = NULL;
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 归并排序
void Merge(SqList &L, SqList &TP, int left, int mid, int right)
{
    for (int i = left; i <= right; ++i)
    {
        TP[i] = L[i];
    }
    int s1 = left;
    int s2 = mid + 1;
    int k = left;
    while (s1 <= mid && s2 <= right)
    {
        if (TP[s1] <= TP[s2])
        {
            L[k++] = TP[s1++];
        }
        else
        {
            L[k++] = TP[s2++];
        }
    }
    while (s1 <= mid)
    {
        L[k++] = TP[s1++];
    }
    while (s2 <= right)
    {
        L[k++] = TP[s2++];
    }
}

void MergeSort(SqList &L, SqList &TP, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(L, TP, left, mid);
    MergeSort(L, TP, mid + 1, right);
    Merge(L, TP, left, mid, right);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
// 基数排序
int getkey(T value, int k)
{
    int key;
    while (k >= 0)
    {
        key = value % 10;
        value /= 10;
        k--;
    }
    return key;
}

void Distribute(SqList &L, int n, List (&lt)[10], int k)
{
    for (int i = 0; i < 10; ++i)
    {
        clear(&lt[i]);
    }
    int key;
    for (int i = 0; i < n; ++i)
    {
        key = getkey(L[i], k);
        push_back(&lt[key], L[i]);
    }
}

void Collect(SqList &L, List (&lt)[10])
{
    int k = 0;
    for (int i = 0; i < 10; ++i)
    {
        Node *p = lt[i].first->next;
        while (p != NULL)
        {
            L[k++] = p->data;
            p = p->next;
        }
    }
}

void RadixSort(SqList &L, int n)
{
    List list[10];
    for (int i = 0; i < 10; ++i)
    {
        InitList(&list[i]);
    }

    for (int i = 0; i < 3; ++i)
    {
        Distribute(L, n, list, i);
        Collect(L, list);
    }
}
//////////////////////////////////////////////////