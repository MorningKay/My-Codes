#include<stdio.h>
int main(void)
{
	//显示从1到n的值
	/*
	int i = 1;
	int n = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", i);
	}
	//先执行语句1，再通过2判断条件，执行循环语句，再执行语句3开始下一次循环（通过表达式2判断真假），直到表达式2为假终止循环
	*/
	
	//计算从1开始到n的累加值
	int i = 0;
	int n = 0;
	int sum = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("sum:%d\n", sum);

	return 0;
}