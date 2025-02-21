#include <stdio.h>
int main() 
{
    int men, women, children;
    int total_people = 30;
    int total_cost = 50;
    int id = 1;
    printf("ID\tMEN\tWOMEN\tCHILDREN\n");
    printf("---------------------------------\n");    
    for (men = 0; men <= total_people; men++) 
    {
        for (women = 0; women <= total_people - men; women++) 
        {
            children = total_people - men - women;
            if (men * 3 + women * 2 + children == total_cost) 
            {
                printf("%-2d\t%-5d\t%-6d\t%-8d\n", id++, men, women, children);
            }
        }
    }
    return 0;
}
