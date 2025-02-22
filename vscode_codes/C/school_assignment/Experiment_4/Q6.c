#include <stdio.h>

int main() 
{
    int n, i;
    int number, sum = 0;
    float avg;

    printf("how many numbers: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("input a integer: ");
        scanf("%d", &number);
        sum += number;
    }
    avg = (float)sum / n;
    printf("sum=%d, avg=%.2f\n", sum, avg);
    return 0;
}
