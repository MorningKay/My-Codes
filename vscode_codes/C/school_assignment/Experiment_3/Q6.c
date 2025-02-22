#include <stdio.h>
#include <math.h>

int main()
{
    double centerX, centerY, radius, x, y;
    double distance;

    printf("请输入圆的圆心坐标：");
    scanf("%lf,%lf", &centerX, &centerY);

    printf("请输入圆的半径：");
    scanf("%lf",&radius);

    printf("请输入要判断的点的坐标(x,y)：");
    scanf("%lf,%lf", &x, &y);

    distance = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));

    if (fabs(distance - radius) <= 1e-6)
        printf("该点在圆上\n");
    else if (distance < radius)
        printf("该点在圆内\n");
    else
        printf("该点在圆外\n");
    
    return 0;
}
