#include<stdio.h>
int main(void)
/*
循环的步骤写法
1.定义变量i和n
2.输入n的值
3.循环语句（循环要做的事请）：输出当前的数据（i的值）
4.思考循环的开始条件：i从1开始
5.思考循环的结束条件：i++，i>n
6.循环的条件：i<=n
*/

//显示从1到n的数字
{
	/* while 循环 -- 先验证条件后运行
	int i = 1;
	int n = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	while (i <= n)
	{
		printf("%d\n", i);
		i++;
	}
	*/

	/* do...while 循环 -- 先运行后验证条件
	int i = 1;
	int n = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	do
	{
		printf("%d\n", i);
		i++;
	}
	while (i <= n);//此时while后要加分号
	*/

	//需要注意！！
	/*
	int i = 5;
	int sum = 0;
	while (i < 5)
	{
		sum += i;
		i++;
	}
	printf("%d\n", sum);//0
	*/

	/*
	* int i = 5;
	int sum = 0;
	do
	{
		sum += i;
		i++;
	}while (i < 5);
	printf("%d\n", sum);//5
	*/
	//由此可见：do while结构语句至少执行一次！！尽管第一个条件不满足也要执行

	return 0;
}