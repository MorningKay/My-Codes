def part_c(initial_deposit):
	#########################################################################
	
	
	##################################################################################################
	## Determine the lowest rate of return needed to get the down payment for your dream home below ##
	##################################################################################################
	
	the_initial_deposit = float(input('Enter the initial deposit: '))
	down_payment = 800000*0.25
	min_rate = 0.0
	max_rate = 1.0
	steps = 0
	if (the_initial_deposit*((1+max_rate/12)**36)) < (down_payment - 100):
	    r = None
	    print('Best savings rate:', r)
	    print('Steps in bisection search: 0 [May vary based on how you implemented your bisection search]')
	else:
	    while (down_payment - the_initial_deposit*((1+min_rate/12)**36)) * (down_payment - the_initial_deposit*((1+max_rate/12)**36)) < 0:
	        r = (min_rate + max_rate) / 2
	        if (down_payment - the_initial_deposit*((1+min_rate/12)**36)) * (down_payment - the_initial_deposit*((1+r/12)**36)) < 0:
	            max_rate = r
	        else:
	            min_rate = r
	        steps += 1
	        if ((down_payment - the_initial_deposit*((1+r/12)**36)) > -100) and ((down_payment - the_initial_deposit*((1+r/12)**36)) < 100):
	            break
	    print('Best savings rate:', r, '[or very close to this number]')
	    print('Steps in bisection search:', steps, '[May vary based on how you implemented your bisection search]')
	return r, steps