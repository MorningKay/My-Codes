#include<stdio.h>
typedef int TYPE;
typedef struct student
{
	int num;
	int score[3];
	float avg;
}STU;
int main(void)
{
	int a;
	TYPE b;//相当于int b;

	STU Tom = { 15,{90,95,80},83.3 };
	int i = 0;
	printf("我的序号是：%d\n", Tom.num);
	for (i = 0; i < 3; i++)
	{
		printf("第%d门的成绩是：%d\n", i + 1, Tom.score[i]);
	}
	printf("平均分是：%f\n", Tom.avg);
	return 0;
}