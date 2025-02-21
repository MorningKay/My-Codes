#include "SeqStack_int.h"

void DecConvert(int value, int n)
{
    SeqStack st;
    InitStack (&st);
    int v;

    while (value)
    {
        Push(&st, value % n);
        value /= n;
    }
    // Show(&st);

    while (!IsEmpty(&st))
    {
        GetTop(&st, &v);
        Pop(&st);
        printf("%d", v);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./Convert value base_n.\n");
        return 1;
    }
    
    int value = atoi(argv[1]); 
    int base_n = atoi(argv[2]); 
    
    if (base_n < 2 || base_n > 16) 
    {
        printf("Base_n must be between 2 and 16.\n");
        return 1;
    }

    DecConvert(value, base_n);

    return 0;
}
