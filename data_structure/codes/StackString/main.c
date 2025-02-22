#include "StackString.h"

int main()
{
    SString S;
    InitString(S);
    StrAssign(S, "ababcababcab");

    SString T;
    InitString(T);
    StrAssign(T, "abc");

    SString V;
    InitString(V);
    StrAssign(V, "xy");

    StrReplace(S, T, V);

    PrintString(S);
}