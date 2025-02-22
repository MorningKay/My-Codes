#include<stdio.h>
#include<string.h>
int main(void)
{
	//char str[10] = "你好";
	//gets(str);//输入字符串
	//puts(str);//输出字符串
	//printf("\n");

	//char a[10] = "ABCDefgh";
	//char b[10] = "EFGH";
	//strcpy(a, b);//把b复制给a，也相当于把b的第五个'\0'赋值给e
	//puts(a);
	//puts(b);
	//putchar(a[5]); //b的第六个元素'f'仍然存在，但是输出时到'\0'就停止
	////确保目标存放地址足够大
	//printf("\n");

	//char a[10] = "ABCD";
	//char b[10] = "EFGH";
	//strcat(a, b);//把b的字符串连接到a后面
	//puts(a);
	//puts(b);
	//printf("\n");

	//char a[10] = "ABCDF";
	//char b[10] = "ABCDEFG";
	//int result = 0;
	//result = strcmp(a, b);//比较大小，依次对比每个字符的ASCII码值
	//printf("%d\n", result);
	//result = strcmp(b, a);//比较大小，依次对比每个字符的ASCII码值
	//printf("%d\n", result);
	//str1 == str2，返回零
	//str1 < str2，返回负数
	//str1 > str2，返回正数
	
	//对于中文字符串用来判断是否相等，判断大小没有意义
	/*char a[10] = "ABCDF";
	int result = 0;
	printf("请输入你的性别（男或女）:");
	gets(a);
	if (strcmp(a, "女") == 0)
		printf("是个美女哦\n");
	else if (strcmp(a, "男") == 0)
		printf("是个帅哥哦\n");*/

	return 0;
}
//写一个输出字符串长度的函数
//方法1：
//int myStrlen(char str[])//char* str
//{
//	int i = 0;
//	while (str[i])//while (str[i] != '\0')//对字符串的遍历
//	{
//		i++;
//	}
// return i;
//}

//方法2：
//int myStrlen(char* p)
//{
//	int i = 0;
//	while (*p)//while (*p != '\0')
//	{
//		p++;
//		i++;
//	}
//	return i;
//}

//方法3：
//int myStrlen(char* p)
//{
//	int i = 0;
//	while (*p)//while (*(p + i) != '\0')
//	{
//		i++;
//	}
//	return i;
//}