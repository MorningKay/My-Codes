#include<stdio.h>
#include<string.h>

//文件在读写过后光标会移动，所以本节中程序需要单个使用或者使用fseek调整光标位置

typedef struct
{
	char name[24];
	char tel[20];
}NODE;
int main(void)
{
	FILE* fp;//定义了一个文件指针
	char ch = 0;
	char str[20] = "abcdef";
	NODE cl[5] = {
		{"张三","10086"},
		{"李四","10010"},
		{"王五","10000"},
	};
	//用绝对路径的方式，以可读可写的模式打开文件
	//不添加路径打开文件时，要求该文件和源文件在同一目录下
	//文件打开成功，则返回该文件的地址，打开失败则返回NULL
	fp = fopen("F:\\DeskTop\\1.txt", "r+");


	//if (fp == NULL)
	//{
	//	printf("1.txt文件打开失败！\n");
	//}
	//else
	//{
	//	printf("1.txt文件打开成功！\n");	
	//	ch = fputc('A', fp);//写入一个'A'
	//	if (ch == EOF)
	//		printf("写入失败\n");
	//	else
	//		printf("写入成功\n");	
	//	fclose(fp);//关闭文件
	//}


	//if (fp == NULL)
	//{
	//	printf("1.txt文件打开失败！\n");
	//}
	//else
	//{
	//	printf("1.txt文件打开成功！\n");
	//	ch = fgetc(fp);//从文件中读出一个字符
	//	while (!feof(fp))//循环的把文件中的所有字符读出来
	//	//每读一个/每写一个字符光标自动后移，只要不为0就继续输出
	//	{
	//		printf("读出来的字符：%c\n", ch);
	//		ch = fgetc(fp);
	//	}
	//	fclose(fp);//关闭文件
	//}


	//if (fp == NULL)
	//{
	//	printf("1.txt文件打开失败！\n");
	//}
	//else
	//{
	//	printf("1.txt文件打开成功！\n");
	//	fgets(str, 5, fp);//从文件中读出一行字符串 
	//	//5个最多只会读出4个，n个最多只会读出n-1个，会默认在结尾补'\0'
	//	puts(str);
	//	fclose(fp);//关闭文件
	//}


	//if (fp == NULL)
	//{
	//	printf("1.txt文件打开失败！\n");
	//}
	//else
	//{
	//	printf("1.txt文件打开成功！\n");
	//	fwrite(&cl[0],sizeof(NODE),3,fp);//往文件中写入数据
	//	fclose(fp);//关闭文件
	//}


	//if (fp == NULL)
	//{
	//	printf("1.txt文件打开失败！\n");
	//}
	//else
	//{
	//	printf("1.txt文件打开成功！\n");
	//	fread(&cl[3], sizeof(NODE), 1, fp);//从文件中读出数据
	//	printf("读出来的姓名：%s\n", cl[3].name);
	//	printf("读出来的号码：%s\n", cl[3].tel);
	//	fclose(fp);//关闭文件
	//}


	if (fp == NULL)
	{
		printf("1.txt文件打开失败！\n");
	}
	else
	{
		printf("1.txt文件打开成功！\n");
		fwrite(&cl[0], sizeof(NODE), 3, fp);//往文件中写入数据
		fseek(fp, 0, SEEK_SET);//设置文件的读写位置，回到文件开头，往后偏移0个字节的位置
		fread(&cl[3], sizeof(NODE), 1, fp);//从文件中读出数据
		printf("读出来的姓名：%s\n", cl[3].name);
		printf("读出来的号码：%s\n", cl[3].tel);
		fclose(fp);//关闭文件
	}

	//fseek(fp, 2 * sizeof(NODE). SEEK_SET);//读出第三个联系人的信息，回到文件开头，往后偏移2个sizeof(NODE)个字节的位置
	//fseek(fp, -1 * sizeof(NODE), SEEK_END);//读出最后一个联系人的信息，回到文件末尾，往回偏移sizeof(NODE)个字节的位置
	return 0;
}