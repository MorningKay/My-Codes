#include "SeqStack.h"

int main()
{
    SeqStack st;
    InitStack(&st);

    ElemType v;
    // for (int i = 1; i <= 10; i++)
    // {
    //     Push(&st, i);
    // }
    printf("请输入要插入的数据(-1结束):>");
    ElemType Item;
    while (scanf("%d", &Item), Item != -1)
    {
        Push(&st, Item);
    }
    Show(&st);
    GetTop(&st, &v);
    printf("%d 出栈.\n", v);
    Pop(&st);
    Show(&st);
}