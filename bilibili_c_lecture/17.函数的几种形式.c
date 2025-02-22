#include<stdio.h>
void printfData(void);//函数的声明
void printfN(int n);
int sum(int n);

int main(void)
{
	int n = 0;
	int su = 0;
	printf("请输入n的值：");
	scanf_s("%d", &n);
	/*printfData();
	printfN(n);*/
	su = sum(n);//函数的调用
	if (su==-1)
	{
		printf("形参异常！请输入正常的数据\n");
	}
	else
	{
		printf("1+2+...+%d的值：%d\n", n, su);
	}
	return 0;
}

//函数的功能：输出1--10之间的数据
//函数的返回值类型：如果不需要返回计算的结果，则不需要返回值
//函数的参数:如果不需要传数据过来参与运算，则为空
void printfData(void)
{
	//编写函数要实现的功能
	int i = 1;
	for (i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
	}
}

//函数的功能：输出1--n之间的数据
//函数的返回值类型
//函数的参数:如果需要传数据过来参与运行，则需要形参
void printfN(int n)
{
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", i);
	}
}

//函数的功能：计算1+2+...+n的值
//函数的返回值类型：如果有计算结果需要返回，则需要返回值类型
//函数的参数:如果需要传数据过来参与运行，则需要形参
int sum(int n)
{
	int i = 0;
	int s = 0;
	//输入
	if (n < 1)//形参的异常判断
		return -1;//返回异常结果
	for (i = 1; i <= n; i++)//计算
	{
		s += i;
	}
	//别在这插入printf语句，会报错
	//一个函数最好只有一个功能
	return s;
}