#include<stdio.h>
int main(void)
{
	int a[5] = { 10,20,30,40,50 };//数组元素之间的地址是相连的
	int* p1;//指针变量p1
	int* p2;
	//数组中的元素的地址相隔四个字节
	printf("a[0]的地址：%d\n", &a[0]);
	printf("a[1]的地址：%d\n", &a[1]);
	printf("a[2]的地址：%d\n", &a[2]);
	printf("a[3]的地址：%d\n", &a[3]);
	printf("a[4]的地址：%d\n", &a[4]);
	printf("\n");

	//数组名代表数组的首地址（首元素地址），即&a[0]，是一个常量，不可以修改
	printf("a代表的地址：%d\n", a); //即&a[0]
	printf("a+1代表的地址：%d\n", a + 1);//即&a[1]
	printf("a+2代表的地址：%d\n", a + 2);//即&a[2]
	printf("a+3代表的地址：%d\n", a + 3);//即&a[3]
	printf("a+4代表的地址：%d\n", a + 4);//即&a[4]
	printf("&a[2]+2的地址：%d\n", &a[2] + 2);//即&a[4]
	printf("\n");

	printf("*(a+2)的值：%d\n", *(a + 2));//即a[2]
	printf("*a+2的值：%d\n", *a + 2);//12,相当于a[0] + 2
	printf("\n");

	p1 = &a[2];//相当于p1 = &a[2];
	printf("p1代表的地址：%d\n", p1); //即&a[2]
	printf("p1+1代表的地址：%d\n", p1 + 1);//即&a[3]
	printf("p1+2代表的地址：%d\n", p1 + 2);//即&a[4]
	printf("p1+3代表的地址：%d\n", p1 + 3);//指针偏移，野指针
	printf("p1+4代表的地址：%d\n", p1 + 4);//
	printf("\n");

	p2 = a;//相当于p2 = &a[0];
	printf("*p2代表的地址：%d\n", *p2); //a[0]
	printf("*(p2+1)代表的地址：%d\n", *(p2 + 1));//a[1]
	printf("*(p2+2)代表的地址：%d\n", *(p2 + 2));//a[2]
	printf("*(p2+3)代表的地址：%d\n", *(p2 + 3));//a[3]
	printf("*(p2+4)代表的地址：%d\n", *(p2 + 4));//a[4]
	printf("\n");

	printf("a[0]的值：%d\n", a[0]);
	printf("p2[0]的值：%d\n", p2[0]);//即a[0]
	printf("\n");

	printf("p1[0]的值：%d\n", p1[0]);//即a[2]
	printf("p1[1]的值：%d\n", p1[1]);//即a[3]
	printf("\n");

	printf("%d\n", *p2);//a[0]
	p2++;//p2 = p2 + 1 = &a[1];
	//注意：这里不能写a++，a是常量不能进行修改
	printf("%d\n", *p2);//a[1]
	printf("\n");
	printf("%d\n", *p2++);//20，即a[1]的值，p = p + 1; 同优先级从右向左，先读后写
	printf("%d\n", *p2);//30，即a[2]的值
	return 0;
}