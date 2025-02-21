#include "SeqStack_char.h"

void PrintStack(SeqStack *s)
{
    for (int i = 0; i < s->top; ++i)
    {
        printf("%c", s->base[i]);
    }
    printf("\n");
}

void LineEdit()
{
    SeqStack st;
    InitStack(&st);

    char ch = getchar();
    while (ch != '$')
    {
        while (ch != '$' && ch != '\n')
        {
            switch (ch)
            {
                case '#':
                {
                    Pop(&st);
                    break;
                }
                case '@':
                {
                    clear(&st);
                    break;
                }
                default:
                {
                    Push(&st, ch);
                    break;
                }
            }
            
            ch = getchar();
        }
        PrintStack(&st);
        ch = getchar();
    }
    destory(&st);
}

int main()
{
    LineEdit();
}