#include <stdio.h>
int main()
{
    int a, n, i;
    int tmp = 0;
    int sum = 0;
    printf("please input a and n ：");
    scanf("%d,%d", &a, &n);
    printf("a=%d,n=%d\n", a, n);
    for (i = 0; i < n; i++)
    {
        tmp = tmp * 10 + a;
        sum += tmp;
    }
    printf("a+aa+...=%d\n", sum);
    return 0;
}
