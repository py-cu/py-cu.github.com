#!/usr/bin/env python

""" Get next day of week, e.g. next Saturday. """

import datetime


days_of_the_week = {d: i for i,d in enumerate('Mon,Tue,Wed,Thu,Fri,Sat,Sun'.split(',') ) }

def get_next_day_of_week(day, starting_date=None):
    """ Get the next day of the week, counting from today, unless another date
        is passed in """

    # default to today as starting day
    if not starting_date:
        starting_date = datetime.datetime.today()

    # iterate through the days of the week to find the date for the given day
    for i in range(1, 8):
        next_day = starting_date + datetime.timedelta(i)
        if next_day.weekday() == days_of_the_week[day]:
            return next_day.strftime('%Y-%m-%d')

if __name__ == '__main__':
	print get_next_day_of_week('Sat')
