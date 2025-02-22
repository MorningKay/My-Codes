#include <stdio.h>

int main() 
{
    int num;

    printf("Enter a data:");
    scanf("%d", &num);

    if (num % 4 == 0 && num % 14 == 0)
        printf("%d can be divided by 4 and 14.\n", num);
    else
        printf("%d cannot be divided by 4 and 14.\n", num);

    return 0;
}
