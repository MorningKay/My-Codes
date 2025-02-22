def part_b(yearly_salary, portion_saved, cost_of_dream_home, semi_annual_raise):
	#########################################################################
	
	
	###############################################################################################
	## Determine how many months it would take to get the down payment for your dream home below ## 
	###############################################################################################
	
	salary = float(input('Enter your yearly salary: '))
	save_portion = float(input('Enter the percent of your salary to save, as a decimal: '))
	cost = float(input('Enter the cost of your dream home: '))
	semi_annual_raise = float(input('Enter the semi-annual raise, as a decimal: '))
	portion_down_payment = cost*0.25
	rate = 0.05/12
	amount_save = 0
	months = 0
	monthly_deposit = salary/12*save_portion
	while amount_save < portion_down_payment:
	    amount_save = amount_save + monthly_deposit + amount_save * rate
	    months = months + 1
	    if months % 6 == 0:
	        monthly_deposit = monthly_deposit * (1 + semi_annual_raise)
	print('Number of months:', months)
	return months