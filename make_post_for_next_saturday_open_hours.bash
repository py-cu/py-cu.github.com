#!/usr/bin/env bash

#########################################################################
# Create, commit, and push post for next open hours event.
#########################################################################

# get next Tues from Python script
next_saturday=`python get_next_saturday.py`

# finish building the file's name, e.g. 2014-11-18-Open-Hours.md
file_name=$next_saturday"-Open-Hours.md"

# copy template text to file with file_name
cp open_hours_post_text.txt _posts/$file_name

# commit and push to github
git add _posts/$file_name
git commit _posts/$file_name -m "Added post for next open hours event."
git push
