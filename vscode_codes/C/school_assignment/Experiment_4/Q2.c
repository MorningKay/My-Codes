#include <stdio.h>
int main() 
{
    int a, d;
    for (a = 1; a <= 26; a++) 
    {
        for (d = 1; d < 7; d++) 
        {
            if (a + (a + d) + (a + 2 * d) + (a + 3 * d) == 26) 
            {
                if (a * (a + d) * (a + 2 * d) * (a + 3 * d) == 880) 
                {
                    for (int i = 0; i < 20; i++) 
                    {
                        printf("%d ", a + i * d);
                    }
                    printf("\n");
                    return 0;
                }
            }
        }
    }
    return 0;
}
