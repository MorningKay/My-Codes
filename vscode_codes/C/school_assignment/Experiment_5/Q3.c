#include <stdio.h>

long Fibonacci(int n);
int count = 0;

int main()
{
    int n, x;
    printf("Input n:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        count = 0;
        x = Fibonacci(i);
        printf("Fib(%d)=%d, count=%d\n", i, x, count);
    }
    return 0;
}

long Fibonacci(int n)
{
    count++;
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}
