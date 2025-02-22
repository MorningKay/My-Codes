#include <stdio.h>
int main() 
{
    char ch;
    int length = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        length++;
    }
    printf("Your message was %d character(s) long.\n", length);
    return 0;
}
