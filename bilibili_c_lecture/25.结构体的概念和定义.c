#include<stdio.h>
//定义结构体包含学生的序号、C语言成绩、PS成绩、平均分
struct student//student是结构体名
{
	int num;
	int c_score;
	int ps_score;
	float avg;
}Jerry,Jim;//Jerry是结构体变量
//数据类型本身不会占据内存空间，定义后的变量才占据内存空间
int main(void)
{
	//变量的定义：类型名 变量名;
	int a;
	//struct student是类型名
	struct student Tom = { 10,90,98,94.5 };//Tom是变量名 在定义中赋值与数组类似
	a = 50;//给a赋值
	Tom.num = 12;//给Tom的num赋值
	Tom.c_score = 95;
	Tom.ps_score = 96;
	Tom.avg = 95.5;
	printf("序号：%d\n", Tom.num);
	printf("C语言成绩：%d\n", Tom.c_score);
	printf("PS成绩：%d\n", Tom.ps_score);
	printf("平均分：%f\n", Tom.avg);
	return 0;
}
