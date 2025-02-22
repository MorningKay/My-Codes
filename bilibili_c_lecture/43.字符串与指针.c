#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[10] = "ABCD";
	char* p;//char型指针变量
	char* p1;
	p = str;//p = &str[0];
	*p = 'X';//str[0] = 'X';
	printf("%s\n", str);//从首元素开始输出
	printf("%s\n", &str[2]);//从第三个元素开始输出
	printf("%s\n", p);
	*(p + 2) += 32;//p[2] += 32;//str[2] += 32;
	printf("%s\n", str);
	printf("%s\n", p);
	p1 = "HIJK";//p1指向字符串常量的首地址
	printf("%s\n", p1);//从首元素开始输出
	printf("%s\n", p1 + 2);//从第三个元素开始输出
	return 0;
}