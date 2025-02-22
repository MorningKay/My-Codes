#include<stdio.h>
int main(void)
{
	int a = 0;
	int b = 0;
	int max = 0;
	printf("请依次输入a和b的值：");
	scanf_s("%d%d", &a, &b);
	max = a > b ? a : b;//条件表达式  语句1? 语句2: 语句3 （语句1为真即为语句2，反之为语句3）相当于if else精简版
	printf("max:%d\n", max);
	return 0;
}