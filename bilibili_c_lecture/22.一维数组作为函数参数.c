#include<stdio.h>
#define SIZE 5
void input(int a[], int len);//函数的声明
void output(int a[], int len);
int main(void)
{
	int i = 0;
	int arr[SIZE] = { 90,80,85,95,70 };
	//顺序输入
	input(arr, SIZE);//输入arr的数组，arr与a共用同一个内存块
	//顺序输出
	output(arr, SIZE);
}

//函数的功能：
//顺序输入一位数组的数据
//一维数组作为函数参数
void input(int a[],int len)
{
	int i = 0;
	for (i = 0; i < len; i++)//遍历
	{
		printf("请输入第%d个数据：", i + 1);
		scanf_s("%d", &a[i]);
	}
}

void output(int a[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)//遍历
	{
		printf("第%d个的数据:%d\n", i + 1, a[i]);
	}
}