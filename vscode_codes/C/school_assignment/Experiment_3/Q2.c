#include <stdio.h>

int main() 
{
    float w, h, t;

    printf("请输入体重（千克）和身高（米）：");
    scanf("%f %f", &w, &h);

    t = w / (h * h);

    if (t < 18)
        printf("低体重\n");
    else if (t >= 18 && t < 25)
        printf("正常体重\n");
    else if (t >= 25 && t < 27)
        printf("超重体重\n");
    else
        printf("肥胖\n");

    return 0;
}
