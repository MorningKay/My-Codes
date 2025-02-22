#include<stdio.h>
void fun1(int a);
void fun2(int c);
int main(void)
{
	auto int a = 10;//局部变量 相当于省略了栈变量关键字auto 开辟a的内存块
	{
		int j = 20;//局部变量，开辟j的内存块
	}//销毁j的内存块
	fun1(1);//2
	fun1(2);//2 fun1函数中的b运行完就销毁
	printf("\n");
	fun2(1);//2 
	fun2(2);//3 fun2函数中的c运行完未销毁，继续运算
	return 0;
}
void fun1(int a)//局部变量 函数调用时开辟a的内存块
{
	int b = 1;//局部变量 函数执行到时开辟b的内存块
	b++;
	printf("%d\n", b);
}//函数执行结束后销毁a和b的内存块
void fun2(int a)//局部变量
{
	static int c = 1;//局部变量 但是编译和销毁时间不一样 主函数结束时才销毁变量
	c++;
	printf("%d\n", c);
}