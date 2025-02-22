#include<stdio.h>
#define SIZE 3
#define N 5
typedef struct student
{
	int num;
	int score[SIZE];
}STU;
int main(void)
{
	STU Tom = { 10,{90,95 ,80} };
	STU class7[N] = { 0 };
	STU* p;//结构体指针变量，存放STU型结构体变量的地址
	int i = 0;
	int j = 0;
	//从键盘输入5个同学的序号及三门成绩，使用结构体指针
	p = class7;//相当于p = &class7[0];

	for (i = 0; i < N; i++)
	{
		printf("请输入第%d个同学的序号：", i + 1);
		//scanf_s("%d", &p[i].num);//相当于scanf_s("%d", &class7[i].num);
		scanf_s("%d", &p->num);
		for (j = 0; j < SIZE; j++)
		{
			printf("请输入第%d门课的成绩：", j + 1);
			//scanf_s("%d", &p[i].score[j]);//scanf_s("%d", &class7[i].score[j]);
			scanf_s("%d", &p->score[j]);
		}
		p++;//让p指向下一个元素
	}

	p = class7;//相当于p = &class7[0];//前面已经对p执行了运算，所以这里要重新赋值p
	for (i = 0; i < N; i++)
	{
		printf("第%d个同学的序号：%d\n", i + 1, p->num);//相当于printf("第%d个同学的序号：%d", i + 1, class7[i].num);
		for (j = 0; j < SIZE; j++)
		{
			printf("第%d门课的成绩：%d分\n", j + 1, p->score[j]);//printf("第%d门课的成绩：%d分\n", j + 1, class7[i].score[j]);
		}
		p++;//让p指向下一个元素
	}
	return 0;
}