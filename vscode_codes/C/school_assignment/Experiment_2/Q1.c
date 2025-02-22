#include <stdio.h>

int main() 
{
    int item_number, year, month, day;
    float unit_price;

    printf("Enter item number: ");
    scanf("%d", &item_number);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (yy mm dd): ");
    scanf("%d %d %d", &year, &month, &day);

    printf("Item     Unit       Purchase \n");
    printf("%-9d$%-9.2f%02d/%02d/%02d\n", item_number, unit_price, month, day, year);

    return 0;
}
