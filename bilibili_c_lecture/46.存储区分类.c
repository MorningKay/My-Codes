#include<stdio.h>

int a = 10;//全局变量，静态区（全局区）
int fun(void);
int main(void)
{
	int b = 20;//局部变量，栈区
	b = 40;
	//20 = 40;//常量区的数据不可更改
	fun(b);
	return 0;
}
int fun(int x)//代码区
{
	static int c = 1;//局部变量，静态区（全局区）
	c += x;
	return c;
}