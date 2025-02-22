#include<stdio.h>
#define SIZE 5
int main(void)
{
	int i = 0;
	int arr[SIZE] = { 90,80,85,95,70 };
	//顺序输入
	for (i = 0; i < SIZE; i++)//遍历
	{
		printf("请输入第%d个数据：",i+1);
		scanf_s("%d",&arr[i]);
	}
	//顺序输出
	for (i = 0; i < SIZE; i++)//遍历
	{
		printf("第%d个的数据:%d\n", i + 1, arr[i]);
	}

	return 0;
}