#!/usr/bin/env bash

#########################################################################
# Create, commit, and push post for next hack night.
#########################################################################
# TODO: make post for next *Tuesday*, rather than just 7 days from now.

## get today's date for the file name, e.g. 2014-11-11
#today=`date +"%Y-%m-%d"`

## take it to next week
#seven_days_from_today=`date -j -v +7d -f "%Y-%m-%d" $today +%Y-%m-%d`

# get next Tues from Python script
next_tues=`python get_next_tues.py`

# finish building the file's name, e.g. 2014-11-18-Hack-Session.md
#file_name=$seven_days_from_today"-Hack-Session.md"
file_name=$next_tues"-Hack-Session.md"

# copy template text to file with file_name
cp hack_night_post_text.txt _posts/$file_name

# commit and push to github
git add _posts/$file_name
git commit _posts/$file_name -m "Added post for next hack night."
git push
