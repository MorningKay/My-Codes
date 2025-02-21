#include <stdio.h>

int main() 
{
    int age;
    printf("请输入一个人的年龄:");
    scanf("%d", &age);

    if (age < 0)
        printf("非法的输入\n");
    else if (age >= 6 && age <= 18)
        printf("该人隶属于初等教育群体\n");
    else if (age < 6 || age > 60)
        printf("该人是老幼人群\n");
    else
        printf("这是一个成年人\n");
    
    return 0;
}
