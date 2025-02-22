#include "HString.h"

int main()
{
    HString S;
    InitString(&S);
    StrAssign(&S, "abcdefghij");

    StrDelete(&S, 2, 3);

    PrintString(&S);
}