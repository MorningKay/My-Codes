#include<stdio.h>
#define M 3
#define N 4
int main(void)
{
	int a[M] = { 10,20,30 };//定义了数组长度为3的一维数组
	int b[M][N] = { {1,4,7,10},{2,5,8,11},{3,6,9,12} };//定义了一个3行4列的二维数组
	//相当于3个数组长度为4的一维数组
	//printf("总字节数：%d\n\n", sizeof(b));//4*3*4=48

	/*一维数组的遍历
	int i = 0;
	for (i = 0; i < M; i++)
	{
		printf("%d\n", a[i]);
	}*/

	//二维数组的遍历 按行输出
	int i = 0, j = 0;
	for (i = 0; i < M; i++)//行下标遍历
	{
		for (j = 0; j < N; j++)
		{
			printf("%d\t", b[i][j]);//列下标遍历
		}
		printf("\n");
	}

	printf("\n");
	
	//按列输出
	for (j = 0; j < N; j++)//列下标遍历
	{
		for (i = 0; i < M; i++)
		{
			printf("%d\t", b[i][j]);//行下标遍历
		}
		printf("\n");
	}
	return 0;
}