#include "Sort.h"

// 直接、二路、折半、希尔插入
// 冒泡排序
// #define USE_ZERO_SPACE

int main()
{
#ifdef USE_ZERO_SPACE
    SqList L = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    int n = 9;
#else
    // SqList L = {49, 38, 65, 97, 76, 13, 27, 49};
    // int n = 8;

    // 基数排序的数组
    SqList L = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    int n = 10;
#endif
    
    // InsertSort(L, n);

    // BInsertSort(L, n);

    // TWayInsertSort(L, n);

    // int delta[] = {5, 3, 2, 1};
    // int t = sizeof(delta) / sizeof(int);
    // ShellSort(L, n, delta, t);

    // BubbleSort(L, n);

    // int low = 0;
    // int high = n - 1;
    // QuickSort(L, low, high);

    // SelectSort(L, n);

    // TreeSelectSort(L, n);

    // HeapSort(L, n);
    
    // SqList TP;
    // MergeSort(L, TP, 0, n - 1);

    RadixSort(L, n);

#ifdef USE_ZERO_SPACE
    for (int i = 1; i < n; ++i)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
#else
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
#endif
}


// 表插入
/*
int main()
{
    SqList L = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    int n = 9;
    Table tb;
    tb[0].data = MAXVALUE;
    tb[0].link = 0;
    for (int i = 1; i < n; ++i)
    {
        tb[i].data = L[i];
        tb[i].link = 0;
    }

    TableInsertSort(tb, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", tb[i].data);
    }
    printf("\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", tb[i].link);
    }
    printf("\n");
}
*/