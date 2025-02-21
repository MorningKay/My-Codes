#include <stdio.h>

int Gcd(int a, int b);

int main()
{
    int num1, num2, result;
    printf("请输入两个正整数：");
    scanf("%d %d", &num1, &num2);
    result = Gcd(num1, num2);
    if (result != -1)
        printf("最大公约数是：%d\n", result);
    else
        printf("输入的数必须为正整数。\n");
    return 0;
}

int Gcd(int a, int b)
{
    if (a <= 0 || b <= 0)
        return -1;

    if (a == b)
        return a;
    else if (a > b)
        return Gcd(a - b, b);
    else
        return Gcd(a, b - a);
}
