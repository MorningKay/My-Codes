#include<stdio.h>
int main(void)
{
	int a = 10;
	int b = 5;
	printf("%d\n", a > b);//1
	printf("%d\n", a < b);//0
	printf("%d\n", a > 10);//0
	printf("%d\n", a >= 10);//1
	printf("%d\n", a <= 10);//1
	printf("%d\n", a == b);//0
	printf("%d\n\n", a != b);//1
	//True输出为1，False输出为0

	printf("%d\n", a > b && a < b);//0
	printf("%d\n", a > b && a != b);//1
	printf("%d\n", a && b);//1
	printf("%d\n", a < 10 && b++);//0
	printf("%d\n\n", b);//5 逻辑与的短路特性，上式逻辑与前结果为假，则不进行逻辑与后的逻辑运算直接判定整式为假，因此b++的运算也未执行，此时输出b结果仍为5

	printf("%d\n", b++ && a < 5);//0
	printf("%d\n\n", b);//6 若把b++写在前，整式为假但是优先运行逻辑与前的语句，此时b++的运算仍然执行，此时b输出结果为6
	// &&运算符参与运算的对象只要不为0即为真（负数也为真），都为真结果为真，一个为假结果为假

	b--;
	printf("%d\n", a == b || a < b);//0
	printf("%d\n", a > b || a != b);//1
	printf("%d\n", a || b);//1
	printf("%d\n", a != 5 || b++);//1
	printf("%d\n\n", b);//5 逻辑或的短路特性，上式逻辑或前结果为真，不进行逻辑或后的逻辑运算，直接判定整式为真，因此b++的运算未执行，此时输出b结果仍未5

	printf("%d\n", b++ || a != 10);//1
	printf("%d\n\n", b);//6 同理，写在前面即可运行，此时b输出结果为6
	// ||运算符参与的运算的对象只要一个为真结果就为真，都为加结果为假

	b--;
	printf("%d\n", !(a > b));//0
	printf("%d\n", !(a < b));//1
	printf("%d\n", !a);//0
	printf("%d\n", !a > b);//0 !的优先级很高，先算!a为0，故此式为假
	// !运算符将真的值改为假，将假的值改为真
	return 0;
}