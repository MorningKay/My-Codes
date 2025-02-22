# Problem 1 - Bisection Search Practise
# Write a program using bisection search to find the forth root of a number inputted by the 
# user. Print the forth root calculated with max error of 0.01. 

# x = float(input("Using bisection search calculate the forth root of: " ))
# epsilon = 0.01
# if x>1:
#     low = 0 # FILL IN
#     high = x # FILL IN
# else:
#     low = x
#     high = 1
# ans = (low+high)/2.0 # FILL IN
# while abs(ans**4-x)>epsilon:
#     if ans**4>x:
#         high = ans
#     else:
#         low = ans
#     ans = (high+low)/2.0
# print(f'the forth root of {x} is {ans}')



# Problem 2 - Functions 
# Write a Python function to check whether a number falls in a given range. 

# def check_range(num,lb,hb):
#     return num>lb and num<hb
# num = 30
# lb = 0
# hb = 20
# print(check_range(num,lb,hb))



# Problem 3 - Functions 
# Write a Python function to check whether a number is perfect or not.
# (In number theory, a perfect number is a positive integer that is equal 
# to the sum of its proper positive divisors, excluding the number itself).

# def check_positive(num):
#     the_sum = 0
#     for i in range(1,num):
#         if num%i == 0:
#             the_sum += i
#     return the_sum == num

# for i in range(1,10):
#     if check_positive(i):
#         print(f'{i} is a positive num')
#     else:
#         print(f'{i} is not a positive num')



# Problem 4 - Approximation Algorithm (see Lecture 5 slides for similar problem)
# Write an approximation algorithm to calculate the forth root of some 
# number inputted by the user. 
# Print the result and the number of iterations required to reach that result. 
# The program should not accept negative numbers. Initial parameters epsilon 
# (i.e. accuracy), initial guess, increment and num_guesses are defined below.

# example initial parameters
epsilon = 0.01
ans = 0.0
increment = 0.001
num_guesses = 0

x = float(input('type a number to find forth root: '))
while abs(ans**4 - x)>epsilon:
    ans += increment
    num_guesses += 1
    if ans**4 > x:
        print(ans, ans**4-x, num_guesses)
        break
print(f'the forth root of {x} is {ans}, the number of guess is {num_guesses}')