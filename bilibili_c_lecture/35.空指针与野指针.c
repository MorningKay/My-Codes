#include<stdio.h>
int main(void)
{
	/*
	int a = 0;
	int* p;
	*p = 20;//错误，p是野指针，无法访问
	printf("%d\n", a);
	*/

	/*
	int a = 0;
	int* p = NULL;
	*p = 20;//错误，p是空指针，无法访问
	//空指针有一个确定的值 —— “空”
	printf("%d\n", a);
	*/

	int a = 0;
	int* p = NULL;
	p = &a;
	*p = 20;
	{
		int b = 30;
		p = &b;
	}
	*p = 50;//p是野指针，因为此时b被销毁了，内存块与b没有关系，但仍然存在
	printf("%d\n", a);
	printf("%d\n", *p);
	return 0;
}