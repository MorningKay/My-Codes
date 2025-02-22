#include<stdio.h>
#define SIZE 5
int main(void)
{
	//变量的定义：类型名 变量名
	int a;
	//数组的定义：类型名 数组名[数组元素个数]
	int arr[5];//相当于定义了5个int型变量
	int d[SIZE];//宏替换，在编译前就完成了将SIZE替换为5的替换，相当于int d[5];
	return 0;
}