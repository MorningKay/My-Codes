#include<stdio.h>
#include<string.h>
int main(void)
{
	int a[5] = { 1,3,5,7,9 };
	char str1[5] = { 'A','B','C','D','E' };
	char str2[5] = "ABCDE";
	char str3[] = "ABCDEF";//省略长度会自动在结尾补'\0'
	int i = 0;
	/*for (i = 0; i < 5; i++)
	{
		printf("%c\n", str1[i]);
	}*/
	printf("%s\n", str1);//字符串的输出遇到'\0'就结束，但这个字符串中没有'\0'，所以输出会出问题
	//若改为char str1[5] = { 'A','B','C','D','\0' };或者char str1[5] = { 'A','B','C','D' };就不会有问题
	printf("%s\n", "ABCDE");
	printf("%s\n", str2);//字符串的输出遇到'\0'就结束，但这个字符串中没有'\0'，所以输出会出问题
	//若改为char str2[5] = "ABCD";则没有问题
	printf("%s\n", str3);//字节长度为7
	str3[1] = 'x';
	printf("%s\n", str3);

	//str2 = "HIJK";//错误，数组数组名代表数组的首元素地址，是地址常量
	//str2[5] = "HIJK";//错误，数组越界（指数组的第五个元素）
	
	//数组名代表数组的首元素地址，是地址常量，不能修改
	//字符串存储应该给'\0'留空间不然会有问题
	return 0;
}