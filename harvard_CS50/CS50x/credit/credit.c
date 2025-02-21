#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long card_number = get_long("Number: ");
    if (card_number < 1000000000000 || card_number > 9999999999999999)
    {
        printf("INVALID\n");
        return 0;
    }
    int two_times_sum = 0;
    int not_two_times_sum = 0;
    int check;
    int total_sum;
    int start_number = card_number;
    while (card_number > 10)
    {
        not_two_times_sum += card_number % 10;
        card_number /= 10;
        check = 2 * (card_number % 10);
        if (check > 10)
            two_times_sum += (check % 10) + (check / 10);
        else
            two_times_sum += check % 10;
        card_number /= 10;
        // printf("%d, %d\n", two_times_sum, not_two_times_sum);
    }
    total_sum = card_number + two_times_sum + not_two_times_sum;
    if (total_sum % 10 == 0)
    {
        while (start_number > 0)
        {
            if (start_number == 34 || start_number == 37)
            {
                printf("American Experess\n");
                return 0;
            }
            else if (start_number == 51 || start_number == 52 || start_number == 53 ||
                     start_number == 54 || start_number == 55)
            {
                printf("MasterCard\n");
                return 0;
            }
            else if (start_number == 4)
            {
                printf("VISA\n");
                return 0;
            }
            start_number /= 10;
        }
    }
    else
        printf("INVALID\n");
    // printf("%d, %ld\n", total_sum, card_number);
    return 0;
}
