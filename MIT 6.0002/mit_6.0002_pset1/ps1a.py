###########################
# 6.0002 Problem Set 1a: Space Cows 
# Name:
# Collaborators:
# Time:

from ps1_partition import get_partitions
import time

#================================
# Part A: Transporting Space Cows
#================================

# Problem 1
def load_cows(filename):
    """
    Read the contents of the given file.  Assumes the file contents contain
    data in the form of comma-separated cow name, weight pairs, and return a
    dictionary containing cow names as keys and corresponding weights as values.

    Parameters:
    filename - the name of the data file as a string

    Returns:
    a dictionary of cow name (string), weight (int) pairs
    """
    cows = {}
    with open(filename, "r") as file:
        for line in file:
            key, value = line.strip().split(',')
            cows[key] = int(value)
    return cows

# Problem 2
def greedy_cow_transport(cows,limit=10):
    """
    Uses a greedy heuristic to determine an allocation of cows that attempts to
    minimize the number of spaceship trips needed to transport all the cows. The
    returned allocation of cows may or may not be optimal.
    The greedy heuristic should follow the following method:

    1. As long as the current trip can fit another cow, add the largest cow that will fit
        to the trip
    2. Once the trip is full, begin a new trip to transport the remaining cows

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)
    
    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    trips = []
    have_transported = []
    while len(have_transported) != len(cows):
        trip = []
        trip_limit = 0
        for key in sorted(cows.keys(), key=lambda k: cows[k], reverse=True):
            if key not in have_transported and trip_limit + cows[key] <= limit:
                trip.append(key)
                trip_limit += cows[key]
                have_transported.append(key)
            if trip_limit == limit:
                break
        trips.append(trip)
    return trips

# Problem 3
def brute_force_cow_transport(cows,limit=10):
    """
    Finds the allocation of cows that minimizes the number of spaceship trips
    via brute force.  The brute force algorithm should follow the following method:

    1. Enumerate all possible ways that the cows can be divided into separate trips 
        Use the given get_partitions function in ps1_partition.py to help you!
    2. Select the allocation that minimizes the number of trips without making any trip
        that does not obey the weight limitation
            
    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)
    
    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    for partition in get_partitions(cows.keys()): 
        for trip in partition:
            weight = 0
            for cow in trip:
                weight += cows[cow]
            if weight > limit:
                break
        else:
            return partition
        
# Problem 4
def compare_cow_transport_algorithms():
    """
    Using the data from ps1_cow_data.txt and the specified weight limit, run your
    greedy_cow_transport and brute_force_cow_transport functions here. Use the
    default weight limits of 10 for both greedy_cow_transport and
    brute_force_cow_transport.
    
    Print out the number of trips returned by each method, and how long each
    method takes to run in seconds.

    Returns:
    Does not return anything.
    """
    cows = load_cows("ps1_cow_data.txt")
    # Greedy algorithm
    start = time.time() 
    cows_greedy = greedy_cow_transport(cows, limit=10)
    end = time.time() 
    print(f"The time of greedy algorithm is: {end - start}, the length is {len(cows_greedy)}")
    
    # Brute force algorithm
    start = time.time() 
    cows_brute = brute_force_cow_transport(cows, limit=10)
    end = time.time() 
    print(f"The time of brute force algorithm is: {end - start}, the length is {len(cows_greedy)}")


if __name__ == "__main__":
    compare_cow_transport_algorithms()
