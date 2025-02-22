#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a = 0;
	int* p;
	int* p1;
	p = &a;//指向a的内存地址
	*p = 10;//相当于a = 10;

	p1 = (int*)malloc(4);
	//申请了一块4个字节堆内存，里面的数据是未知的，不会赋初值
	if (p1 == NULL)
		printf("无法申请到堆内存\n");
	*p1 = 20;
	printf("%d\n", *p1);
	free(p1);//释放p1指向的堆内存


	int a[5] = { 0 };
	int* p;
	int* p2;
	p = a;
	*p = 20;//a[0] = 20;

	p2 = (int*)calloc(5,sizeof(int));
	//申请了一块长度为5，每个为4个字节的堆内存，里面的数据是未知的，不会赋初值
	p2[0] = 10;
	free(p2);
	return 0;
}