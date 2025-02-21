#include<stdio.h>
int main(void)
{
	/*
	分数等级：
	90--100：A
	80—89：B
	70--79：C
	60--69：D
	60以下：不合格
	*/

	int score = 0;
	printf("请输入成绩：");
	scanf_s("%d", &score);
	if (score >= 0 && score <= 100)
	{
		if (score >= 90)
			printf("等级：A\n");
		else if (score >= 80)//else已经包含score<90 下面同理
			printf("等级：B\n");
		else if (score >= 70)
			printf("等级：C\n");
		else if (score >= 60)
			printf("等级：D\n");
		else
			printf("等级：不合格\n");
	}
	else
	{
		printf("您输入的成绩有误！\n");
	}

	return 0;
}