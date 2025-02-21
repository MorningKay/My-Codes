#include<stdio.h>
int fac(int n);
int main(void)
{
	int factorial,n;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	factorial = fac(n);
	if (factorial == -1)
		printf("形参的值异常！");
	else
		printf("%d的阶乘为%d\n", n, fac(n));
	return 0;
}

//函数的功能：求n的阶乘
int fac(int n)
{
	if (n < 0)//形参的异常检查
		return -1;//返回异常值
	else if (n == 1 || n == 0)
		return 1;
	else
		return n * fac(n - 1);//函数的递归
	//即换个思路求n*(n-1)*(n-2)*...*2*1
}