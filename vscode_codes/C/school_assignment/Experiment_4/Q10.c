#include <stdio.h>

int factorial(int n);

int main()
{
    int n, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }
    printf("The sum of factorials from 1 to %d is: %d\n", n, sum);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}