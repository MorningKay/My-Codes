#include<stdio.h>

//不要运行这个文件会报错！！仅展示

int c = 0;//全局变量
//c的作用域是文件作用域
extern int fun(int b);//函数的声明：相当于省略了个extern
extern int d;//扩展作用域的时候不能赋值
int main(void)
{
	int a = 10;//局部变量 函数作用域
	//a的作用域 即a的使用范围仅在主函数中，其他函数需要再次定义a
	a = 20;
	{
		int a;
		int j = 0;//语句块作用域 仅在这个复合语句中使用
		j = 50;
	}
	a = fun(5);//就近原则 复合语句中定义了变量a，仍然优先取主函数定义的变量a
	return 0;
}
int d = 10;
int fun(int b)//函数作用域
{
	int i = 0;
	b = 30;
	return b;
}