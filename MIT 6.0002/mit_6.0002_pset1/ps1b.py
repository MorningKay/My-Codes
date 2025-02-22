###########################
# 6.0002 Problem Set 1b: Space Change
# Name:
# Collaborators:
# Time:
# Author: charz, cdenise

#================================
# Part B: Golden Eggs
#================================

# Problem 1
def dp_make_weight(egg_weights, target_weight, memo = {}):
    """
    Find number of eggs to bring back, using the smallest number of eggs. Assumes there is
    an infinite supply of eggs of each weight, and there is always a egg of value 1.
    
    Parameters:
    egg_weights - tuple of integers, available egg weights sorted from smallest to largest value (1 = d1 < d2 < ... < dk)
    target_weight - int, amount of weight we want to find eggs to fit
    memo - dictionary, OPTIONAL parameter for memoization (you may not need to use this parameter depending on your implementation)
    
    Returns: int, smallest number of eggs needed to make target weight
    """
    # Base case: if the target weight is 0, no eggs are needed
    if target_weight == 0:
        return 0
    
    # Try to fetch the result from the memo
    try:
        return memo[target_weight]
    except KeyError:
        # If the result is not in the memo, compute it
        min_eggs = float('inf')
        
        # Try every possible egg weight
        for weight in egg_weights:
            if weight <= target_weight:
                # Recursively find the minimum number of eggs for the remaining weight
                num_eggs = 1 + dp_make_weight(egg_weights, target_weight - weight, memo)
                # Update the minimum number of eggs if the current combination is better
                if num_eggs < min_eggs:
                    min_eggs = num_eggs
        
        # Store the result in the memo before returning
        memo[target_weight] = min_eggs
        return min_eggs


# EXAMPLE TESTING CODE, feel free to add more if you'd like
if __name__ == '__main__':
    egg_weights = (1, 5, 10, 25)
    n = 99
    print("Egg weights = (1, 5, 10, 25)")
    print("n = 99")
    print("Expected ouput: 9 (3 * 25 + 2 * 10 + 4 * 1 = 99)")
    print("Actual output:", dp_make_weight(egg_weights, n))
    print()