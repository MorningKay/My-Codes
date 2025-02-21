// 1 线性表合并

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>

// #define ElemType int
// #define MAXSIZE 20

// typedef struct SqList
// {
//     ElemType *base;
//     int length;
//     int max_size;
// } SqList;

// void InitSqList(SqList *sl)
// {
//     sl->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
//     assert(sl->base != NULL);
//     sl->length = 0;
//     sl->max_size = MAXSIZE;
// }

// void Push_back(SqList *sl, ElemType x)
// {
//     if (sl->length > sl->max_size)
//         return;
    
//     sl->base[sl->length] = x;
//     sl->length++;
// }

// void InsertSqList(SqList *sl, ElemType arr[], int n)
// {
//     if (n > sl->max_size)
//         return;
//     for (int i = 0; i < n; i++)
//     {
//         Push_back(sl, arr[i]);
//     }
// }

// void show(SqList *sl)
// {
//     for (int i = 0, n = sl->length; i < n; i++)
//     {
//         printf("%d ", sl->base[i]);
//     }
//     printf("\n");
// }

// void Merge_list(SqList *sl1, SqList *sl2, SqList *sl)
// {
//     if (sl1->length + sl2->length > MAXSIZE)
//         return;
    
//     int i, j, k;
//     i = j = k = 0;
//     while (i < sl1->length && j < sl2->length)
//     {
//         if (sl1->base[i] < sl2->base[j])
//         {
//             sl->base[k++] = sl1->base[i++];
//         }
//         else
//         {
//             sl->base[k++] = sl2->base[j++];
//         }
//     }

//     while (i < sl1->length)
//     {
//         sl->base[k++] = sl1->base[i++];
//     }

//     while (j < sl2->length)
//     {
//         sl->base[k++] = sl2->base[j++];
//     }

//     sl->length = k;
// }

// int main()
// {
//     int arr1[5] = {1, 3, 5, 7, 9};
//     int arr2[5] = {2, 4, 6, 8, 10};
//     SqList sl1;
//     SqList sl2;
//     SqList sl_merge;
//     InitSqList(&sl1);
//     InitSqList(&sl2);
//     InitSqList(&sl_merge);
//     InsertSqList(&sl1, arr1, 5);
//     InsertSqList(&sl2, arr2, 5);
//     Merge_list(&sl1, &sl2, &sl_merge);
//     show(&sl_merge);
// }