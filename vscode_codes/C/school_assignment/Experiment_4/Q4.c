#include <stdio.h>
#include <math.h>
int main() 
{
    int n;
    double sqrt_value;
    while (1) 
    {
        printf("Please enter n: ");
        scanf("%d", &n);
        if (n < 0) 
        {
            printf("Program is over!\n");
            break;
        }
        sqrt_value = sqrt(n);
        printf("sqrt(%d) = %.2f\n", n, sqrt_value);
    }
    return 0;
}
