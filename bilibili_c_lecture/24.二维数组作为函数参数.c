#include<stdio.h>
#define M 3
#define N 4
void input(int b[][N], int row, int column);
void output(int b[M][N], int row, int column);
int main(void)
{
	int arr[M][N] = { 0 };
	//int arr[M][N] = { {1,4,7,10},{2,5,8,11},{3,6,9,12} };
	int i = 0;
	int j = 0;
	input(arr, M, N);//函数的调用
	printf("\n");
	output(arr, M, N);//函数的调用
	return 0;
}

//函数的功能：按行输入二维数组的部分元素
void input(int b[][N],int row,int column)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("请输入第%d行第%d列的数据：", i, j);
			scanf_s("%d", &b[i][j]);
		}
	}
}

//函数的功能：按行输出二维数组的部分元素
void output(int b[M][N],int row,int column)//int b[][N]; 可省略行数不能省略列数
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)//行下标遍历
	{
		for (j = 0; j < column; j++)
		{
			printf("%d\t", b[i][j]);//列下标遍历
		}
		printf("\n");
	}
}