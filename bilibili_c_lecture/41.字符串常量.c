#include<stdio.h>
#include<string.h>
int main(void)
{
	//字符串：由一对双引号括起来的0个或多个字符
	printf("%s\n","abcEFG");//输出字符串
	printf("占据的字节数:%d\n", sizeof("abcEFG"));//字符串的尺寸，7个
	//6个字符各占1个，再加结尾要要加一个'\0'，再占据一个字节
	printf("长度：%d\n\n", strlen("abcEFG"));//字符串的长度，6个

	printf("占据的字节数:%d\n", sizeof("abc\0EFG"));//字符串的尺寸，8个
	printf("长度：%d\n\n", strlen("abc\0EFG"));//字符串的长度，3个
	//字符串长度：从字符串左边开始计数，到第一个'\0'为止，且'\0'不参与计数

	printf("占据的字节数:%d\n", sizeof(""));//字符串的尺寸，1个
	printf("长度：%d\n\n", strlen(""));//字符串的长度，0个
	return 0;
}