#!/bin/bash

#
# Check palindrome v2 - 0x2 - Looking Glass
# Andrei Bratkovski
#

#
# Read in the string that use enters to see if it is a
# palindrome
#
read -p "Enter an input string: " inputString

#
# Open reverse string to be initialized so that reverse input
# string can be built into it
#
REVERSE=''

#
# Append each element from end of inputString backwards to the new
# string, creating a reversed input string
#
for ((increment=${#inputString}; increment>=0; increment--))
	do REVERSE="$REVERSE"${inputString:$increment:1}
done

#
# Check if reversed string is exactly the same as input
# string
#
if [[ "$REVERSE" == "$inputString" ]]
then
	printf "This is a palindrome\n"
else
	printf "This is NOT a palindrome\n"
fi

