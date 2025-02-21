#include<stdio.h>
void fun1(void);
void fun2(void);
void fun3(void);
double fun4(int x);
int main(void)
{
	int i = 0;
	int* p;//定义了一个指针型变量p，可以存放int型变量的地址

	void(*pfun)(void);//中间的括号不能省！！
	//定义了一个函数指针变量pfun,可以存放函数的地址
	//返回值类型为void，形参为void的函数
	double(*pfun4)(int x);
	//定义了一个函数指针变量pfun4,可以存放函数的地址
	//返回值类型为double，有一个形参为int的函数
	p = &i;
	*p = 10;//相当于i  =10;
	printf("函数fun1的地址：%d\n", fun1);
	printf("函数fun2的地址：%d\n", fun2);
	printf("函数fun3的地址：%d\n", fun3);
	pfun = fun1;//指向fun1的入口地址
	pfun();//相当于fun1();
	pfun = fun2;//指向fun2的入口地址
	pfun();//相当于fun2();
	pfun = fun3;//指向fun3的入口地址
	(*pfun)();//相当于fun3();


	int* pstr[3];//定义了一个指针数组，相当于定义了3个int型指针变量
	pstr[0] = &i;

	void(*pf[3])(void);//定义了一个函数指针数组，相当于定义了3个函数指针变量
	pf[0] = fun1;
	pf[0]();
	pf[1] = fun2;
	pf[1]();
	pf[2] = fun3;
	pf[2]();
	return 0;
}
void fun1(void)
{
	printf("******\n");
}
void fun2(void)
{
	printf("++++++\n");
}
void fun3(void)
{
	printf("======\n");
}
double fun4(int x)
{
	x = 4;
	printf("$$$$$$\n");
	return 3.14;
}