#!/bin/bash

# ^bash shabang

###############################################################
#															  #
# Andrei Bratkovski 10/20/17 - usf0 - UNIX/LINUX FUNDAMENTALS #
#															  #
###############################################################


#################################################
#
# Declare variables
#
# Initialize MIN and MAX variables for default 0-15
# binary data table printing.  If command line arguemnts are specified,
# these values will change.
#
INDEX=0
MIN=0
MAX=15
NUMEX='^[0-9]+$'
NUM_ARGUMENTS=$#

#################################################
#
# Checking for properly given command line arguments
#	
# If argument 1 or 2 are not given to specification, program prints out error
# message based on the situation. If there are more than 2 arguments given, let user
# know that the signed implementation is not in this program.
#
# If argument 1 or argument 2 are not within implementation range (1-255) OR they are given
# as something other than a whole number (NUMEX), error message prints and program exits. 
#
# If argument 1
# is given and argument 2 is NOT given, argument 1 MUST be less than or equal to 15, as that is the default
# MAX value
#

#
# Argument 1 checks, description in above paragraph
#
if [ "${NUM_ARGUMENTS}" -gt 0 ]; then
	if ! [[ $1 =~ $NUMEX ]]; then
		printf "ERROR: Argument 1 needs to be a whole number between 1 and 255\n"
		exit 1
	else
		if [[ "$1" -ge 0 ]] && [[ "$1" -le 255 ]]; then
			MIN=$1
		else
			printf "ERROR: Argument 1 is not within range ( 0-255 )\n"
			exit 1
		fi
	fi
fi

#
# Argument 2 checks, description in above paragraph
#
if [ "${NUM_ARGUMENTS}" -gt 1 ]; then
	if ! [[ $2 =~ $NUMEX ]]; then
		printf "ERROR: Argument 2 needs to be a whole number between 1 and 255\n"
		exit 1
	else
		if [[ "$2" -ge "$1" ]] && [[ "$2" -le 255 ]]; then
			MAX=$2
		else
			printf "ERROR: Argument 2 is not within range ( MIN value ( defaults to 0 ) -255 )\n"
			exit 1
		fi
	fi
fi

#
# Checking if more than 2 arguments are given. If that is the case, let user know
# that signed functionality is not implemented
#
if [ "${NUM_ARGUMENTS}" -gt 2 ]; then
	printf "SIGNED FUNCTIONALITY NOT IMPLEMENTED\n"
	exit 1
fi

#
# If one argument is given, check that min value is not greater than
# default max value ( 15 ). Range needs to be specified properly by the user
# or program before printing the data table
#
if [ "$MIN" -gt "$MAX" ]; then
	printf "ERROR: MIN value cannot be greater than MAX value\n"
	exit 1
fi
#################################################
#
# Binary Data Table
#
# If all logic goes according to specification, print out
# binary data table

#
# print out the header, giving the base format of each column
#
printf "  base 2  |  base 8  |  base10  |  base 16 \n"
printf '%s\n' '----------+----------+----------+-----------'


#
# Iterate over each number from MIN to MAX and print out their
# base 2, base 8, base 10, and base 16 formats
#
for((INDEX=MIN; INDEX<=MAX; INDEX++)); do

	bin=`echo "obase=2;$INDEX" | bc`
	hex=`echo "obase=16;$INDEX" | bc`
	printf "%9.04d |" $bin
	printf "%9.3o |" $INDEX
	printf "%9.01d |" $INDEX
	printf "%6s" " "
	printf "0x%.02X\n" 0x$hex	

done
