#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[10] = "ABCD";
	char ch = 'X';
	//scanf_s("%c", &ch);//单个字符的输入
	//ch = getchar();//单个字符的输入
	//scanf_s("%s", str);//字符串的输入，不能输入带空格的字符串
	//gets(str);//字符串的输入函数，可以输入带空格的字符串
	//printf("%s\n", str);//字符串的输出，对应的是地址
	//printf("%c\n", ch);//单个字符的输出，对应的是变量
	//putchar(ch);//单个字符的输出函数
	//puts(str);//字符串的输出函数，会自动换行

	
	//printf("scanf键盘输入：");
	//scanf("%s", str);//字符串的输入，不能输入带空格的字符串
	//printf("%s\n", str);//字符串的输出

	//getchar();//把上一个输入的回车符号吃掉了
	//printf("gets键盘输入：");
	//gets(str);//字符串的输入函数，能输入带空格的字符串
	//puts(str);//字符串的输出函数
	return 0;
}