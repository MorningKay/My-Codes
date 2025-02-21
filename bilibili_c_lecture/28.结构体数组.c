#include<stdio.h>

//有n个学生的信息（包括学号、成绩），找出成绩最高的学生，并输出该学生的信息

#define N 5
typedef struct student
{
	int num;
	int score;
}STU;//STU是结构体别名
int main(void)
{
	STU class3[N] = { {10,90},{14,70},{8,95} };
	int i = 0;
	int max = 0;//存放最高分所在的结构体数组元素下标
	for (i = 1; i < N; i++)
	{
		if (class3[i].score > class3[max].score)
			max = i;
	}
	printf("成绩最高的学生：\n");
	printf("序号：%d\n", class3[max].num);
	printf("成绩：%d\n", class3[max].score);
	return 0;
}