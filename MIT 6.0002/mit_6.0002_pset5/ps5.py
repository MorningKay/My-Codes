# -*- coding: utf-8 -*-
# Problem Set 5: Experimental Analysis
# Name: 
# Collaborators (discussion):
# Time:

import pylab
import re

# cities in our weather data
CITIES = [
    'BOSTON',
    'SEATTLE',
    'SAN DIEGO',
    'PHILADELPHIA',
    'PHOENIX',
    'LAS VEGAS',
    'CHARLOTTE',
    'DALLAS',
    'BALTIMORE',
    'SAN JUAN',
    'LOS ANGELES',
    'MIAMI',
    'NEW ORLEANS',
    'ALBUQUERQUE',
    'PORTLAND',
    'SAN FRANCISCO',
    'TAMPA',
    'NEW YORK',
    'DETROIT',
    'ST LOUIS',
    'CHICAGO'
]

TRAINING_INTERVAL = range(1961, 2010)
TESTING_INTERVAL = range(2010, 2016)

"""
Begin helper code
"""
class Climate(object):
    """
    The collection of temperature records loaded from given csv file
    """
    def __init__(self, filename):
        """
        Initialize a Climate instance, which stores the temperature records
        loaded from a given csv file specified by filename.

        Args:
            filename: name of the csv file (str)
        """
        self.rawdata = {}

        f = open(filename, 'r')
        header = f.readline().strip().split(',')
        for line in f:
            items = line.strip().split(',')

            date = re.match('(\d\d\d\d)(\d\d)(\d\d)', items[header.index('DATE')])
            year = int(date.group(1))
            month = int(date.group(2))
            day = int(date.group(3))

            city = items[header.index('CITY')]
            temperature = float(items[header.index('TEMP')])
            if city not in self.rawdata:
                self.rawdata[city] = {}
            if year not in self.rawdata[city]:
                self.rawdata[city][year] = {}
            if month not in self.rawdata[city][year]:
                self.rawdata[city][year][month] = {}
            self.rawdata[city][year][month][day] = temperature
            
        f.close()

    def get_yearly_temp(self, city, year):
        """
        Get the daily temperatures for the given year and city.

        Args:
            city: city name (str)
            year: the year to get the data for (int)

        Returns:
            a 1-d pylab array of daily temperatures for the specified year and
            city
        """
        temperatures = []
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        for month in range(1, 13):
            for day in range(1, 32):
                if day in self.rawdata[city][year][month]:
                    temperatures.append(self.rawdata[city][year][month][day])
        return pylab.array(temperatures)

    def get_daily_temp(self, city, month, day, year):
        """
        Get the daily temperature for the given city and time (year + date).

        Args:
            city: city name (str)
            month: the month to get the data for (int, where January = 1,
                December = 12)
            day: the day to get the data for (int, where 1st day of month = 1)
            year: the year to get the data for (int)

        Returns:
            a float of the daily temperature for the specified time (year +
            date) and city
        """
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        assert month in self.rawdata[city][year], "provided month is not available"
        assert day in self.rawdata[city][year][month], "provided day is not available"
        return self.rawdata[city][year][month][day]

def se_over_slope(x, y, estimated, model):
    """
    For a linear regression model, calculate the ratio of the standard error of
    this fitted curve's slope to the slope. The larger the absolute value of
    this ratio is, the more likely we have the upward/downward trend in this
    fitted curve by chance.
    
    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        estimated: an 1-d pylab array of values estimated by a linear
            regression model
        model: a pylab array storing the coefficients of a linear regression
            model

    Returns:
        a float for the ratio of standard error of slope to slope
    """
    assert len(y) == len(estimated)
    assert len(x) == len(estimated)
    EE = ((estimated - y)**2).sum()
    var_x = ((x - x.mean())**2).sum()
    SE = pylab.sqrt(EE/(len(x)-2)/var_x)
    return SE/model[0]

"""
End helper code
"""

def generate_models(x, y, degs):
    """
    Generate regression models by fitting a polynomial for each degree in degs
    to points (x, y).

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        degs: a list of degrees of the fitting polynomial

    Returns:
        a list of pylab arrays, where each array is a 1-d array of coefficients
        that minimizes the squared error of the fitting polynomial
    """
    models = []
    for d in degs:
        model = pylab.polyfit(x, y, d)
        models.append(model)
    return models


def r_squared(y, estimated):
    """
    Calculate the R-squared error term.
    
    Args:
        y: 1-d pylab array with length N, representing the y-coordinates of the
            N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model

    Returns:
        a float for the R-squared error term
    """
    mean = sum(y) / len(y)
    numerator = sum((y - estimated)**2)
    denominator = sum((y - mean)**2)
    r_square = 1 - numerator / denominator
    return r_square

def evaluate_models_on_training(x, y, models):
    """
    For each regression model, compute the R-squared value for this model with the
    standard error over slope of a linear regression line (only if the model is
    linear), and plot the data along with the best fit curve.

    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        R-square of your model evaluated on the given data points,
        and SE/slope (if degree of this model is 1 -- see se_over_slope). 

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.

    Returns:
        None
    """
    for model in models:
        estimated = pylab.polyval(model, x)
        r_square = r_squared(y, estimated)
        pylab.figure()
        pylab.plot(x, y, 'bo', label='Data Points')
        pylab.plot(x, estimated, 'r-', label='Best Fit Curve')
        title = f"Degree: {len(model)-1}, R-squared: {r_square:.4f}"
        if len(model) == 2:
            se_slope = se_over_slope(x, y, estimated, model)
            title += f",\nSE/slope: {se_slope:.4f}"
        
        pylab.title(title)
        pylab.xlabel('Year')
        pylab.ylabel('Temperature (C)')
        pylab.legend()
        pylab.show()

def gen_cities_avg(climate, multi_cities, years):
    """
    Compute the average annual temperature over multiple cities.

    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to average over (list of str)
        years: the range of years of the yearly averaged temperature (list of
            int)

    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the average annual temperature over the given
        cities for a given year.
    """
    y = []
    for year in years:
        cities_temp = []
        for city in multi_cities:
            city_temps = climate.get_yearly_temp(city, year)
            city_avg_temp = sum(city_temps) / len(city_temps)
            cities_temp.append(city_avg_temp)
        cities_avg_temp = sum(cities_temp) / len(cities_temp)
        y.append(cities_avg_temp)
    return pylab.array(y)  

def moving_average(y, window_length):
    """
    Compute the moving average of y with specified window length.

    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        window_length: an integer indicating the window length for computing
            moving average

    Returns:
        an 1-d pylab array with the same length as y storing moving average of
        y-coordinates of the N sample points
    """
    moving_avg = []
    for i in range(len(y)):
        avg = []
        for j in range(window_length):
            idx = i - window_length + j + 1
            if idx >= 0:
                avg.append(y[idx])
        moving_avg.append(sum(avg) / len(avg))
    return pylab.array(moving_avg)

def rmse(y, estimated):
    """
    Calculate the root mean square error term.

    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model

    Returns:
        a float for the root mean square error term
    """
    return (sum((y - estimated)**2) / len(y))**(1/2)

def gen_std_devs(climate, multi_cities, years):
    """
    For each year in years, compute the standard deviation over the averaged yearly
    temperatures for each city in multi_cities. 

    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to use in our std dev calculation (list of str)
        years: the range of years to calculate standard deviation for (list of int)

    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the standard deviation of the average annual 
        city temperatures for the given cities in a given year.
    """
    std_devs = []
    for year in years:
        avg_temps = []
        if year % 4 == 0:
            day = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
        else:
            day = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
        for m in range(1, 13):
            for d in range(1, day[m]+1):
                day_temps = []
                for city in multi_cities:
                    day_temps.append(climate.get_daily_temp(city, m, d, year))
                day_avg = sum(day_temps) / len(day_temps)
                avg_temps.append(day_avg)
        std_devs.append(pylab.std(pylab.array(avg_temps)))
    
    return pylab.array(std_devs)

def evaluate_models_on_testing(x, y, models):
    """
    For each regression model, compute the RMSE for this model and plot the
    test data along with the model’s estimation.

    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        RMSE of your model evaluated on the given data points. 

    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.

    Returns:
        None
    """
    for model in models:
        estimated = pylab.polyval(model, x)
        rmse_val = rmse(y, estimated)
        pylab.figure()
        pylab.plot(x, y, 'bo', label='Data Points')
        pylab.plot(x, estimated, 'r-', label='Best Fit Curve')
        title = f"Degree: {len(model)-1}, RMSE: {rmse_val:.4f}"
        
        pylab.title(title)
        pylab.xlabel('Year')
        pylab.ylabel('Temperature (C)')
        pylab.legend()
        pylab.show()

if __name__ == '__main__':
    
    pass

    # Part A.4
    # I
    # climate = Climate("data.csv")
    # month, day = 1, 10
    # y = []
    # for year in TRAINING_INTERVAL:
    #     y.append(climate.get_daily_temp("NEW YORK", month, day, year))
    
    # y = pylab.array(y)
    # x = pylab.array(TRAINING_INTERVAL)
    # models = generate_models(x, y, [1])
    # evaluate_models_on_training(x, y, models)
    
    # II
    # climate = Climate("data.csv")
    # y = []
    # for year in TRAINING_INTERVAL:
    #     temperatures = climate.get_yearly_temp("NEW YORK", year)
    #     avg_temp = sum(temperatures) / len(temperatures)
    #     y.append(avg_temp)
    
    # y = pylab.array(y)
    # x = pylab.array(TRAINING_INTERVAL)
    # models = generate_models(x, y, [1])
    # evaluate_models_on_training(x, y, models)

    # Part B
    # climate = Climate("data.csv")
    # x = pylab.array(TRAINING_INTERVAL)
    # y = gen_cities_avg(climate, CITIES, TRAINING_INTERVAL)
    # models = generate_models(x, y, [1])
    # evaluate_models_on_training(x, y, models)

    # Part C
    # climate = Climate("data.csv")
    # x = pylab.array(TRAINING_INTERVAL)
    # y = gen_cities_avg(climate, CITIES, TRAINING_INTERVAL)
    # moving_avg = moving_average(y, 5)
    # models = generate_models(x, moving_avg, [1])
    # evaluate_models_on_training(x, moving_avg, models)

    # Part D.2
    # I
    # climate = Climate("data.csv")
    # x = pylab.array(TRAINING_INTERVAL)
    # y = gen_cities_avg(climate, CITIES, TRAINING_INTERVAL)
    # moving_avg = moving_average(y, 5)
    # models = generate_models(x, moving_avg, [1, 2, 20])
    # evaluate_models_on_training(x, moving_avg, models)
    
    # II
    # climate = Climate("data.csv")
    # x = pylab.array(TESTING_INTERVAL)
    # y = gen_cities_avg(climate, CITIES, TESTING_INTERVAL)
    # moving_avg = moving_average(y, 5)
    # models = generate_models(x, y, [1, 2, 20])
    # evaluate_models_on_testing(x, y, models)

    # Part E
    climate = Climate("data.csv")
    x = pylab.array(TRAINING_INTERVAL)
    y = gen_std_devs(climate, CITIES, TRAINING_INTERVAL)
    moving_avg = moving_average(y, 5)
    models = generate_models(x, moving_avg, [1])
    evaluate_models_on_training(x, moving_avg, models)
