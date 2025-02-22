#include <stdio.h>

int main()
{
    int number, reverse_num = 0;

    printf("Please input a three digit number: ");
    scanf("%d", &number);

    if (number < 0) 
    {
        number = -number; 
    }

    while (number > 0) 
    {
        reverse_num = reverse_num * 10 + number % 10;
        number /= 10;
    }

    printf("The reverse number is %d.\n", reverse_num);

    return 0;
}
