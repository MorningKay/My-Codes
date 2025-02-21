def total_luhn(number):
    all_digits_sum = 0
    reversed_number = number[::-1]
    for i in range(len(number)):
        check = 0
        if (i % 2 == 1):
            check = 2 * int(reversed_number[i])
            if (check >= 10):
                all_digits_sum += check % 10 + check // 10
            else:
                all_digits_sum += check
        elif (i % 2 == 0):
            all_digits_sum += int(reversed_number[i])
    return all_digits_sum


def check_number(number, total):
    if (total % 10 == 0):
        if ((len(number) >= 13 and len(number) <= 16) and (number[0] == '4')):
            print("VISA")
        elif ((len(number) == 15) and ((number[:2] == "34") or (number[:2] == "37"))):
            print("AMEX")
        elif ((len(number) == 16) and (51 <= int(number[:2]) <= 55)):
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


credit_number = input("Number: ")
check_number(credit_number, total_luhn(credit_number))
