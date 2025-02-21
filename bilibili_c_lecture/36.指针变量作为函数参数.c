#include<stdio.h>

/*
void fun(int* b);
int main(void)
{
	int a = 10;
	fun(&a);
	printf("%d\n", a);
	return 0;
}
void fun(int* b)
{
	*b = 30;//相当于a = 30;间接的修改a的值
}
*/

void fun1(int* x, int* y);
int* fun2(int* x, int* y);
int main(void)
{
	int a = 10;
	int b = 20;
	int* p;
	fun1(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	p = fun2(&a, &b);
	printf("%d\n", *p);
	return 0;
}
void fun1(int* x,int* y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}
int* fun2(int* x, int* y)
{
	if (*x > *y)
		return x;
	else
		return y;
}