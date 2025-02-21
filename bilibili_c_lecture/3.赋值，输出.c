#include <stdio.h>
int main(void)
{
	int a = 0;
	int b = 20;
	a = 100;
	printf("%d\n", a);//%d:十进制的整数形式输出
	printf("%d,%d\n",a, b);

	char c, d;
	c = 45;//把45赋值给c（把45写入c的内存块中）
	d = c;//把c的值45赋值给d（先读出c的值（45），再把45赋值给d）（把45写入d的内存块中）
	//输出c和d
	printf("c:%d,d:%d\n", c, d);//把c和d的值读出来


	return 0;
}