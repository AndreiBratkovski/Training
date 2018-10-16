#!/bin/bash
#
# Andrei Bratkovski - 0x0 - Move Along Home
#
# Sleep sort
#
# Questions:
# 1. the $* variable means all of the arguments are expanded to a single argument
# delimited by spaces
#
# 2. The & symbol at the end of the function means that when the process starts in the background
# the shell can continue to be used/typed in
#
# 3 and 4. This script is a sleep sort, the reason that it works is that the lower numbers print out
# first because they take the least amount of time to print.  For instance, 37 would take 37 seconds
# to print, while the others are printing before it ( 0 takes 0 seconds, 1 takes 1 second to print) and
# so on. It is a joke algorithm but funny that it works. There are collision which can occur based on
# the ordering.  If a number is small much later in the list, it may not catch up to a previous large number
# due to the waiting time
#
# 
# Run this script as follows:
#   ./script 44.1 33 22 3 11 12 23 0 34 2 45 5 1 3.14159 4
#

#
# Function now checks for the number divided by 10 because
# it reverses the size ordering of larger numbers with smaller
# numbers
#
function process() {
	sleep 	 `bc -l <<< "10/$1"`
	echo  -n "$1 "
}
#
# Trigger variable to change if there is a 0 in the
# input since we cannot divide by 0.
#
trigger=0

#
# Iterate through data as usual, making sure it is not a 0 so that
# it can be divided up
#
for data in $*; do
	if [ $(echo "$data > 0" | bc) -eq 1 ]
	then
		process "$data" &
	else
		let "trigger=trigger+1"
	fi
done

wait

#
# If there is a 0 inthe input, print it
# out last
#
if [ $trigger -gt 0 ]
then
	echo -n "0 "
fi

echo

exit 0
