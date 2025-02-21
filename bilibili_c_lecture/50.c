#include<stdio.h>

int main(void)
{
    int a[][3] = { {1,0,3},{0},{1,1} };
    printf("%d", a[1][2]);
    return 0;
}