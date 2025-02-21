#include<stdio.h>

void fun(void);//函数的声明
int add(int a, int b);//函数的声明：扩展了函数的作用域（使用范围）
//函数的声明记得加分号

//主函数
//int:整型，函数的返回值类型
//main:函数名
//void:空的，函数的参数，函数的形式参数（形参）
int main(void)
{
	//fun();//函数的调用
	int sum = 0;
	sum = add(10, 20);//函数的调用//相当于  sum = 30;
	printf("%d\n", sum);
	return 0;
}

//函数的功能：求a+b的和
//函数的定义
int add(int a, int b)
{
	int c = 0;
	c = a + b;
	return c;
}

//定义函数
void fun(void)
{
	printf("*******\n");
	printf("+++++++\n");
}
//放置一个函数，后续需要使用直接调用函数即可