#include<stdio.h>
int main(void)
{
	//整型变量a，存放整型数据
	int a = 0;
	a = 10;//把10存放到a的内存块中
	printf("%d\n", a);//输出a的值
	printf("%d\n", &a);//输出a的地址（指针） &取地址符号
	printf("%x\n", &a);//输出十六进制的地址
	printf("%p\n", &a);//固定用十六进制输出指针地址
	//a的地址是常量

	//定义了int型指针变量p，p可以存放int型变量的地址
	int* p;//int*是类型名，p是变量名
	int* b, c, * d;//b和d是指针型变量，c是普通int型变量
	p = &a;//把a的地址存放到p的内存块中，且p不能存放整数，只能存放地址数据
	return 0;
}