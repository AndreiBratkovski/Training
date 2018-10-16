#!/usr/bin/python

import sys
import math
import time

########################################################
##
## Error checking
##
if (len(sys.argv) < 2):
	print "Insufficient arguments!"
	sys.exit()

start = float(time.time())
########################################################
##
## Variable declaration
##
factor = 2
flag = 0
number = 2
maxqty = int(sys.argv[1])
qty = 0

########################################################
##
## Main algorithm
##
while (qty < maxqty):

	while (factor <= math.sqrt(number)):

		if (number%factor == 0):
			flag = 1
			break
		factor = factor + 1

	if (flag == 0):
		sys.stderr.write("%d "%number)
		qty = qty+1

	number = number + 1
	flag = 0
	factor = 2
print ""
end = float(time.time())
sys.stdout.write("%8.6f\n"%((end-start)))


