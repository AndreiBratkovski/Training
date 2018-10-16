#
# Primeregbs.py - Andrei Bratkovski
#

#
# Import necessary libraries for command line and math functions
#
import time
import sys
import math

#
# Initialize counter variables
#
maxNumPrimes = int(sys.argv[1])
numPrimes = 0
compositeCounter = 0
lowerBound = 2

#
# Start timer
#
start_time = time.time()

#
# primeregbs algorithm in python
#

#
# Check primality of numbers up to the square root
# of the lowerbound, then add to num of primes if a number
# is prime, until reaching max number of primes
#
while numPrimes < maxNumPrimes:
	increment = 2
	while increment <= math.sqrt(lowerBound):
		if lowerBound % increment == 0:
			compositeCounter += 1
		
		if compositeCounter >= 2:
			break
	
		increment += 1

	if compositeCounter < 1:
		sys.stderr.write(str(lowerBound) + " ")
		numPrimes += 1

	lowerBound += 1
	compositeCounter = 0

print("")

#
# Print ending time
#
print(time.time() - start_time)
