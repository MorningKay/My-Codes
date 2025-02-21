## 6.100A PSet 1: Part A
## Name: MorningKay
## Time Spent:
## Collaborators:

##################################################################################
## Get user input for yearly_salary, portion_saved and cost_of_dream_home below ##
##################################################################################


#########################################################################
## Initialize other variables you need (if any) for your program below ##
#########################################################################


###############################################################################################
## Determine how many months it would take to get the down payment for your dream home below ## 
###############################################################################################

salary = float(input('Enter your yearly salary: '))
save_portion = float(input('Enter the percent of your salary to save, as a decimal: '))
cost = float(input('Enter the cost of your dream home: '))
portion_down_payment = cost*0.25
rate = 0.05/12
amount_save = 0
months = 0
while amount_save < portion_down_payment:
    monthly_deposit = salary/12*save_portion
    amount_save = amount_save + monthly_deposit + amount_save * rate
    months = months + 1
print('Number of months:', months)