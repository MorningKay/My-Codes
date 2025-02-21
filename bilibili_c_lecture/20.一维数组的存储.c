#include<stdio.h>
#define SIZE 5
int main(void)
{
	int a0, a1, a2, a3, a4;
	int arr[SIZE];//相当于定义了5个int型变量
	printf("%d\n", sizeof(a0));//输出a0占据的字节数
	printf("%d\n", sizeof(arr));//输出数组arr占据的字节数：5*4
	printf("总字节数：%d\n", sizeof(arr));//总字节数 = sizeof(类型) * 数组长度;
	printf("长度：%d\n", sizeof(arr) / sizeof(int));//数组长度 = 总字节数 / sizeof(类型)
	printf("长度：%d\n", sizeof(arr) / sizeof(arr[0]));//如果不知道变量类型，也可以知道数组长度
	return 0;
}