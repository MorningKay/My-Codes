#include <stdio.h>

int calculate_sum(int abc);
int print_number(int sum);

int main()
{
    int sum, number;
    printf("请输入你心中所想的数的其他五个数的和值:>");
    scanf("%d", &sum);
    number = print_number(sum);
    if (number == -1)
    {
        printf("你算错了！\n");
        return 1;
    }
    else
    {
        printf("你想的数是%d\n", number);
        return 0;
    }

}

int calculate_sum(int abc)
{
    int a = abc / 100;
    int b = (abc / 10) % 10;
    int c = abc % 10;
    int acb, bac, bca, cab, cba;
    acb = a * 100 + c * 10 + b;
    bac = b * 100 + a * 10 + c;
    bca = b * 100 + c * 10 + a;
    cab = c * 100 + a * 10 + b;
    cba = c * 100 + b * 10 + a;
    return acb + bac + bca + cab + cba;
}

int print_number(int sum)
{
    for (int i = 100; i < 1000; i++)
    {
        if (calculate_sum(i) == sum)
            return i;
    }
    return -1;
}