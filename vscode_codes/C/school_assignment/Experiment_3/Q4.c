#include <stdio.h>

int main() 
{
    int people, coupon_value;
    float original_price = 88.0;
    float discount_price, total_discount_price, final_price, 
            total_coupon_price, total_original_price;
    int coupon_discount = 0;
    int discount_choice;

    printf("请输入本次购买人数和礼品券面额：");
    scanf("%d %d", &people, &coupon_value);

    if (people >= 1 && people <= 2)
        discount_price = original_price * 0.9;
    else if (people >= 3 && people <= 4)
        discount_price = original_price * 0.85;
    else if (people >= 5 && people <= 10)
        discount_price = original_price * 0.8;
    else if (people >= 11 && people <= 15)
        discount_price = original_price * 0.7;
    else if (people > 15)
        discount_price = original_price * 0.65;
    else
        discount_price = original_price;
    
    total_original_price = original_price * people;
    total_discount_price = discount_price * people;

    if (coupon_value == 50)
        coupon_discount = 10;
    else if (coupon_value == 100)
        coupon_discount = 30;
    else if (coupon_value == 200)
        coupon_discount = 80;
    else
    {
        printf("无此券，请重新输入\n");
        return 1;
    }

    if (total_original_price > coupon_discount)
        total_coupon_price = total_original_price - coupon_discount;
    else
        total_coupon_price = total_original_price;
    
    if (total_discount_price < total_coupon_price) 
    {
        discount_choice = 1;
        final_price = total_discount_price;
    } 
    else if (total_discount_price > total_coupon_price) 
    {
        discount_choice = 2;
        final_price = total_coupon_price;
    } 
    else 
    {
        discount_choice = 0;
        final_price = total_discount_price;
    }

    printf("选择: %d, 应付金额: %.2f, 实付金额: %.2f\n", discount_choice, total_original_price, final_price);

    return 0;
}
