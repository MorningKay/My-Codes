#include <stdio.h>
int main() 
{
    int mingAge = 12;
    int motherAge = mingAge + 24;
    int year = 0;
    while (motherAge != 2 * mingAge) 
    {
        year++;
        mingAge++;
        motherAge++;
    }
    printf("year=%d\nmingAge=%d\nmotherAge=%d\n", year, mingAge, motherAge);
    return 0;
}
