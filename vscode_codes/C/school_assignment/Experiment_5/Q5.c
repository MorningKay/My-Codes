#include <stdio.h>
#include <stdbool.h>

void Multiply_table();
bool is_prime(int m);
void Output_prime_num_range(int m, int n);
int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    int select = 1;
    while (select)
    {
        printf("****************************\n");
        printf("*1. 输出九九乘法表         *\n");
        printf("*2. 输出m到n之间质数       *\n");
        printf("*3. 计算a和b的最小公倍数   *\n");
        printf("*0. 退出                   *\n");
        printf("****************************\n");

        printf("请选择:>");
		scanf("%d", &select);
        if (select == 0)
            break;
        switch (select)
        {
            case 1:
            {
                Multiply_table();
                break;
            }
            case 2:
            {
                int m, n;
                printf("请输入m和n:>");
                scanf("%d %d", &m, &n);
                Output_prime_num_range(m, n);
                break;
            }
            case 3:
            {
                int a, b;
                printf("请输入a和b:>");
                scanf("%d %d", &a, &b);
                printf("%d\n", lcm(a, b));
                break;
            }
            default:
            {
                printf("输入的命令错误，请重新输入.\n");
			    break;
            }
        }
    }
}

void Multiply_table()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d×%d=%-2d ", j, i, j * i);
        }
        printf("\n");
    }
}

bool is_prime(int m)
{
    for (int i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
            return false;
    }
    return true;
}

void Output_prime_num_range(int m, int n)
{
    if (m > n || m < 1)
    {
        printf("输入的范围有误，请重新输入.\n");
        return;
    }

    for (int i = m; i <= n; i++)
    {
        if (is_prime(i))
            printf("%d ", i);
    }
    printf("\n");
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}