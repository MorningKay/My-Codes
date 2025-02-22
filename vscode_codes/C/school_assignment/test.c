#include <stdio.h>
int main()
{
    int i = 10;
    switch (i)
    {
        case 9: i += 10;
        case 10: i += 10;
        case 11: i += 10; break;
        default: i += 10;
    }
    printf("i = %d\n", i);
}