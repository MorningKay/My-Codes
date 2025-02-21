#include<stdio.h>
int main(void)
{
	int a = 10;
	a = 5;
	printf("%d\n", a += 5);//相当于 a = a + 5 = 10;
	printf("%d\n", a -= 5);//相当于 a = a - 5 = 5;
	printf("%d\n", a *= 5);//相当于 a = a * 5 = 25;
	printf("%d\n", a /= 5);//相当于 a = a / 5 = 5;
	printf("%d\n", a++);//a = a + 1;
	printf("%d\n\n", a += 1);//a = a + 1; 两式区别在于下面的复合运算符可以改a加的值,例如a+=2 即为a=a+2;

	int b = 6;
	printf("%d\n\n", sizeof(b));//4 指b的字节数为4

	int c = 7;
	float d = 0;
	d = c / 2;//3.000000 因为两个均为整型所以结果为整数
	printf("%f\n", d);
	d = 7.0 / 2;//3.500000 有一个变量为浮点型
	printf("%f\n", d);
	d = (int)7.5 * 2;//14.000000 7.5被强制转换为了整型，此时为7*2=14；
	printf("%f\n", d);
	d = (int)(7.5 * 2);//15.000000 将运算结果15转换为了整型
	printf("%f\n\n", d);

	char e = 5;//4字节
	printf("%d\n", sizeof(a + 6));//混合数据的运算，将char自动转换为了精度更高的int
	return 0;
}