#include <stdio.h>
#include <math.h>

int main() 
{
    int number;
    int digits = 0;
    while (1) 
    {
        printf("Enter a nonnegative integer: ");
        scanf("%d", &number);
        if (number == 0) 
        {
            printf("over.\n");
            break;
        }
        if (number < 0) 
        {
            number = -number;
        }
        if (number == 0) 
        {
            digits = 1;
        } 
        else
        {
            digits = (int)log10(number) + 1;
        }
        printf("The number has %d digit(s).\n", digits);
    }
    return 0;
}
