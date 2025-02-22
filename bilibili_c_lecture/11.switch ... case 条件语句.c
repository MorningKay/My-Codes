#include<stdio.h>
int main(void)
{
	int week = 0;
	printf("今天是星期几：");
	scanf_s("%d", &week);
	switch (week)
	{
	case 1:printf("今天是星期一\n"); break;
	case 2:printf("今天是星期二\n"); break;
	case 3:printf("今天是星期三\n"); break;
	case 4:printf("今天是星期四\n"); break;
	case 5:printf("今天是星期五\n"); break;
	case 6:printf("今天是星期六\n"); break;
	case 7:printf("今天是星期日\n"); break;
	default:printf("输入数据有误！\n");
	}
	return 0;
}