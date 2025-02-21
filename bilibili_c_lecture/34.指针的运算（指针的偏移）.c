#include<stdio.h>
int main(void)
{
	char ch = 0;
	int a = 10;
	float b = 0;
	double d = 0;
	char* p1 = &ch;
	int* p2 = &a;//p2指向a
	float* p3 = &b;
	double* p4 = &d;
	//*后面跟的是哪个变量的地址，*p代表的就是那个变量本身
	//均是基类型，但是占据的字节数都相同，因为都用来存变量的地址，32位计算机占4个字节，64位计算机占8个字节
	printf("%d\n", sizeof(p1));
	printf("%d\n", sizeof(p2)); 
	printf("%d\n", sizeof(p3));
	printf("%d\n", sizeof(p4));
	printf("\n");
	printf("%d\n", &ch);
	printf("%d\n", &a);
	printf("%d\n", &b);
	printf("%d\n", &d);
	printf("\n");

	//地址+1指的是偏移,偏移的量与基类型有关
	printf("2:%d\n", &ch+1);//地址偏移了1个存储单元（1个字节）
	printf("2:%d\n", &a+1);//地址偏移了1个存储单元（4个字节）
	printf("2:%d\n", &b+1);//地址偏移了1个存储单元（4个字节）
	printf("2:%d\n", &d+1);//地址偏移了1个存储单元（8个字节）
	printf("\n");
	
	printf("a的值：%d\n", a);//10
	printf("a的地址：%d\n", &a);
	printf("p2的值：%d\n", p2);
	printf("*p2的值：%d\n", *p2);//10
	printf("\n");

	printf("%d\n", (*p2)++);//相当于a++，10
	printf("a的值：%d\n", a);//11
	printf("a的地址：%d\n", &a);
	printf("p2的值：%d\n", p2);//a的地址
	printf("*p2的值：%d\n", *p2);//11
	printf("\n");

	printf("%d\n", ++ (*p2));//12
	printf("%d\n", ++ * p2);//13，+与*为相同优先级，但是运算顺序是从右向左，所以等效于上式缺省一个括号
	printf("a的值：%d\n", a);//13
	printf("a的地址：%d\n", &a);
	printf("p2的值：%d\n", p2);//a的地址
	printf("*p2的值：%d\n", *p2);//13
	printf("\n");

	printf("%d\n", *p2++);//相当于p++，*p，13，p=p+1=&a+1;
	//等效于printf("%d\n", *(p2++));
	printf("a的值：%d\n", a);
	printf("a的地址：%d\n", &a);
	printf("p2的值：%d\n", p2);//不是a的地址，是&a+1
	printf("*p2的值：%d\n", *p2);//出cup，此时p变成了&a+1，为野指针
	return 0;
}