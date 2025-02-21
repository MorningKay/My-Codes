#include <stdio.h>

int main() 
{
    char input_char, prior, next;

    printf("Enter a character:");
    input_char = getchar();

    while (getchar() != '\n');

    if (input_char == 0) 
    {
        printf("Error: No prior char for the first ASCII character.\n");
        return 1;
    } 
    else if (input_char == 127) 
    {
        printf("Error: No next char for the last ASCII character.\n");
        return 1;
    }

    prior = input_char - 1;
    next = input_char + 1;

    printf("%c\t%c\t%c\n", prior, input_char, next);
    printf("%d\t%d\t%d\n", (int)prior, (int)input_char, (int)next);

    return 0;
}
