#include<stdio.h>
//定义结构体包含学生的序号、3门课的成绩、平均分
struct student//结构体名
{
	int num;
	int score[3];
	float avg;
};
int main(void)
{
	struct student Tom = { 10,{90,80},85.5 };//数组为部分赋初值，则第三门成绩为0
	struct student Jim = { 10,90,80,85.5 };//没有给数组单独划定范围，则默认平均分为0，85.5由于为整型自动变为85
	printf("序号：%d\n", Tom.num);
	printf("成绩1：%d\n", Tom.score[0]);
	printf("成绩2：%d\n", Tom.score[1]);
	printf("成绩3：%d\n", Tom.score[2]);
	printf("平均分：%f\n\n", Tom.avg);

	printf("序号：%d\n", Jim.num);
	printf("成绩1：%d\n", Jim.score[0]);
	printf("成绩2：%d\n", Jim.score[1]);
	printf("成绩3：%d\n", Jim.score[2]);
	printf("平均分：%f\n", Jim.avg);
	return 0;
}