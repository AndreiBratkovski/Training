#!/usr/bin/ruby

require 'benchmark'
	#################################################################
	##
	## Error checking
	##

	#################################################################
	##
	## We are using benchmark to measure the time
	##
	time = Benchmark.measure {
	#################################################################
	##
	## Variable declaration
	##
	max=Integer(ARGV[0])
	flag=0
	number=2
	qty=0

	#################################################################
	##
	## Main algorithm
	##
	#################################################################
	##
	## This loop will iterate until we print out the right amount
	## of prime number
	##
	while qty < max do
		#############################################################
		##
		## Uses the brute force method to check for primality
		##
		for factor in 2..Math.sqrt(number) do
			#########################################################
			##
			## Checks to see if there is a factor. If there is a
			## factor, flag that it is a composite number
			##
			if number%factor == 0 then
				flag = 1
				break
			end
		end
		#############################################################
		##
		##  
		##
		if flag == 0 then
			STDERR.print number
			STDERR.print " "
			qty += 1
		end
		flag = 0
		number += 1
	end
	STDERR.puts ""
}
#####################################################################
##
## Prints out the time
##
puts "%.6f" % time.real
