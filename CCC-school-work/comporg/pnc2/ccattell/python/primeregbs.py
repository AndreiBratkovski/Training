#!/usr/bin/python
import sys
import math
import time

start_time = time.time()

inputValue=int(sys.argv[1])
testNum = 4
primeCount = 2
divisor = 2
primeCheck = 0
##rem = 0
##root = 0

sys.stderr.write("2 3 ")

while primeCount < inputValue:
	root = int(math.sqrt(testNum))

    ##############################################
	while divisor <= root:
		rem = testNum % divisor
##		print(rem)
		if rem == 0:
			primeCheck = 1
			break
		else: 
			primeCheck = 0
			divisor = divisor + 1
    #############################################

##	primeCount = primeCount + 1

	if primeCheck == 0:
		sys.stderr.write("%i " % testNum)
		primeCount = primeCount + 1

	testNum = testNum + 1
	divisor = 2
	
##	if primeCount == inputValue:
##		sys.exit()		

sys.stderr.write("\n")
totalTime = time.time() - start_time
print "%.3f" % totalTime

