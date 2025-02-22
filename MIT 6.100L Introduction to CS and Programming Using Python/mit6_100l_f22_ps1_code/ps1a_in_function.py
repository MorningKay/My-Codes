def part_a(yearly_salary, portion_saved, cost_of_dream_home):
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
	return months