#include "SeqStack_char.h"

bool Check(char *str)
{
    SeqStack st;
    InitStack(&st);

    char v;
    while (*str != '\0')
    {
        if (*str == '[' || *str == '(')
        {
            Push(&st, *str);
        }
        else if (*str == ']')
        {
            GetTop(&st, &v);
            if (v != '[')
            {
                return false;
            }
            Pop(&st);
        }
        else if (*str == ')')
        {
            GetTop(&st, &v);
            if (v != '(')
            {
                return false;
            }
            Pop(&st);
        }
        ++str;
    }
    return IsEmpty(&st);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./BracktesMatch string.\n");
        return 1;
    }
    bool flag = Check(argv[1]);
    if (flag)
    {
        printf("OK!\n");
    }
    else
    {
        printf("Error!\n");
    }
    return 0;
}