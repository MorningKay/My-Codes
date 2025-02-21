#include<stdio.h>
#define M 3
#define N 4
int main(void)
{
	int a[M][N] = { {1,4,7,10},{2,5,8,11},{3,6,9,12} };
	int* p;//绑定一个变量的地址
	int(*p2)[N];//定义了一个行指针，是指针变量，只能存放长度为N的int型数组的地址，绑定的是一行
	int* p3[M];//定义了一个指针数组，长度为M，相当于定义了M个指针变量
	//p=a;//错误，a绑定的是一行
	p = &a[0][0];
	p = a[0];
	//p2 = &a[0][0];//错误
	p2 = a;//p2= &a[0];//绑定第0行
	printf("p代表的地址：%d\n", p);
	printf("p2代表的地址：%d\n", p2);
	//printf("%d\n", *(*(p + 0) + 0));错误的，行指针才能这么用，这里是普通指针
	printf("%d\n", *p);//1
	printf("%d\n", *(*(p2 + 0) + 0));//1
	printf("%d\n", p2[0][1]);//4
	printf("\n");

	p = p + 1;
	p2 = p2 + 1;
	printf("p代表的地址：%d\n", p);
	printf("p2代表的地址：%d\n", p2);
	printf("%d\n", *p);//4
	printf("%d\n", *(*(p2 + 0) + 0));//2
	printf("%d\n", p2[0][1]);//5
	return 0;
}