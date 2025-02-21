#include <stdio.h>
int main()
{
    int a[5];
    a[0] = 2;
    a[1] = 3;
    a[2] = 10;
    a[3] = 5;
    a[4] = 9;
    
    for (int i = 0, money = 0; i < 5; i++)
    {
        money += a[i];
        if (money >= 16)
        {
            printf("number: %d\n", i + 1);
            break;
        }
    }
}