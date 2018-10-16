#!/bin/bash

# prime number calculator, now in bash... if program is executable,
# type ./primeregba.sh QTY to run it, where QTY is the number of primes to calculate

# if program is not executable, type bash primeregba.sh QTY to do the same

# test for a command line argument
if [ -z "$1" ]; then
	echo "Must provide quantity argument" 1>&2
	exit 1
fi

qty=$1 # set quantity 

# I know from testing that if you type "-4" in this kind of script
# bash will read it as -4 for the purpose of doing arithmetic, so
# we can test for a negative number like so
if [ $qty -lt 0 ]; then
	echo "Quantity must be positive" 1>&2
	exit 1
fi

st_time=`date +%s.%N` # start timing

num_primes=0 # number of primes we've found
num=2 # start testing for primes at 2
factor=2 # start factor at 2
prime=1 # is a number prime or not 

# keep checking for primes until we find qty of them 
while [ $num_primes -lt $qty ]
do
	# keep checking a number up to its square root
	while [ $(($factor * $factor)) -le $num ]
	do
		# if factor divides into num, num is composite
		if [ $(($num % $factor)) -eq 0 ]; then
			prime=0
			break
		fi
		# go to next factor
		((factor++))
	done
	# if number is prime, print it 
	if [ $prime -eq 1 ]; then
		printf "%d " $num 1>&2
		((num_primes++))
	else
		prime=1
	fi

	factor=2 # start at 2 again
	((num++)) # go to next number
done

printf "\n" 1>&2 

end_time=`date +%s.%N` # stop timing

diff=$(echo "$end_time - $st_time" | bc) # get elapsed time

printf "%8.4f\n" $diff 
