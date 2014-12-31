#!/usr/bin/env python

""" Get next day of week. """

import datetime

dow= {d:i for i,d in enumerate( 'Mon,Tue,Wed,Thu,Fri,Sat,Sun'.split(',') ) }

def get_next_day_of_week(day, starting_date=None ):
	""" Get the next day of the week, counting from today, unless another date is passed in """
	# not setting starting date in the actual parameter list!
	if not starting_date:
		starting_date = datetime.datetime.today()

	for i in range(1, 8):
		next_day = starting_date + datetime.timedelta(i)
		if next_day.weekday() == dow[day]: return next_day.strftime('%Y-%m-%d')
		# print day.strftime('%Y-%m-%d'), 

if __name__ == '__main__':
	print get_next_day_of_week('Tue')

	# next_tues = datetime.datetime(2015, 1, 6, 20, 53, 32, 941421)
	# print get_next_day_of_week('Tue', next_tues)
			
	# some_day = datetime.datetime(2015, 1, 15, 20, 53, 32, 941421)
	# print get_next_day_of_week('Tue', some_day)