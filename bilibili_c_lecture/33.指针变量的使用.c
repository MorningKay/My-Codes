#include<stdio.h>
int main(void)
{
	int a = 0;
	int b = 0;
	int* p;
	a = 10;
	p = &a;//p存放a的地址，p指向a的内存块，a的地址指的是a第0个字节的地址
	printf("a的值：%d\n", a);//10
	printf("a的地址：%d\n", &a);
	printf("p的值：%d\n", p);//p里面存放的值就是a的地址
	printf("p的地址：%d\n", &p);//p的地址
	printf("*p的值：%d\n", *p);//*p就是a，10
	//*间接访问运算符 间接访问p存放的地址所对应的内存块 也就是a的值
	*p = 20;//相当于a=20;
	printf("a的值：%d\n", a);
	printf("*p的值：%d\n", *p);
	p = &b;//p存放b的地址，p指向b的内存块
	*p = 50;
	printf("a的值：%d\n", a);
	printf("b的值：%d\n", b);
	printf("*p的值：%d\n", *p);
	return 0;
}