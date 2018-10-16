#!/bin/bash

#
# 0x2 - Through the Looking Glass
#
# Check if a string is a palindrome
#

#
# Here would be a great change to use the rev functionality
#

#
# Read in the user's input string
#
read -p "Enter an input string: " inputString

#
# Using the rev unix command, simply check if the string reversed is
# the same as the string forward, then let the user know if it is a
# palindrome
#
if [[ $(rev <<< $inputString) == "$inputString" ]]; then
	printf "%s\n" "Input string is a palindrome!"
else
	printf "%s\n" "Input string is NOT a palindrome!"
fi

