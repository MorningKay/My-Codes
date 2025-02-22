#include<stdio.h>
typedef struct student
{
	int num;
	int score[3];
}STU;
int main(void)
{
	STU Tom = { 10,{90,95,80} };
	STU* p;//结构体指针变量，存放STU型结构体变量的地址
	p = &Tom;
	Tom.score[0] = 75;
	p->score[0] = 100;//相当于Tom.score[0] = 100;
	(*p).score[0] = 120;//相当于Tom.score[0] = 120;
	printf("请输入序号：");
	scanf_s("%d", &p->num);//相当于scanf_s("%d", &Tom.num);
	printf("序号：%d\n", p->num);
	printf("成绩：%d\n", p->score);

	STU class7[5] = { 0 };
	STU* p1;
	p1 = class7;//相当于p = &class7[0];
	p1->num = 20;//相当于class7[0].num = 20;
	p1[0].num = 20;//相当于class7[0].num = 20;
	p1++;//p1 = p1 + 1 = &class[1];
	p->num = 30;//相当于class7[1].num = 30;
	return 0;
}