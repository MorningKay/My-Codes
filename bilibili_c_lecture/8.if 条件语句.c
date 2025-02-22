#include<stdio.h>
int main(void)
{
	/*
	int a = 0;
	int b = 0;
	int max = 0;
	printf("请依次输入a和b的值：");
	scanf_s("%d%d", &a, &b);
	max = a;
	if (max < b)
	max = b;
	printf("max:%d\n", max);

	//输入a与b找出a与b的最大值
	return 0;
	*/

	int a = 0;
	printf("请输入a的值：");//输入提示
	scanf_s("%d", &a);//输入语句
	if (a % 2 != 0)//判断是否为奇数 if条件语句中的语句1可以是多条语句，用{}表示 

	//if后面不要加分号！！！！！！！！！！！！！！！！！

	{
		printf("%d是奇数\n", a);
	}
	printf("*****\n");
	//判断a是否为奇数
	return 0;
}