#include <stdio.h>

int MyPow(int a, int b);

int main()
{
    int a, b;
    printf("input a and b:");
    scanf("%d %d", &a, &b);
    printf("a^b = %d\n", MyPow(a,b));
    return 0;
}

int MyPow(int a, int b)
{
    if (a == 1 || b == 0)
        return 1;
    if (a == 0)
        return 0;

    int power = 1, tmp = a;
    if (a < 0)
        a = -a;
    for (int i = 0; i < b; i++)
    {
        power *= a;
    }
    if (tmp < 0 && b % 2 != 0)
        return -power;
    return power;
}