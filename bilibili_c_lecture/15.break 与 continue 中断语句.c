#include<stdio.h>
int main(void)
{
	/* break 语句
	int i = 1;
	int n = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", i);
		if (i > 10)
			break;//输出到i>10就终止，最终只会显示到11的值
	}
	*/

	//continue语句
	int i = 1;
	int n = 0;
	int sum = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += i;
		printf("sum:%d\n", sum);
		if (sum > 10)
			continue;//符合条件即终止当前循环开始下一次循环
		printf("i=%d\n", i);
	}

	return 0;
}