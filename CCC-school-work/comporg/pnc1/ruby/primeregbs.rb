#!/usr/bin/ruby -w 
# primeregbs.rb - Andrei

#
# Declare variables, and start the timer.
# the max prime number is our first command line
# argument
#
lowerBound = 2
numPrimes = 0

numMaxPrimes = ARGV[0].to_i
compositeCounter = 0
start = Time.now

#
# Iterate over each number up to its square root
# and check if it is prime, adding to a compositeCounter
# to keep track of its primality
#
while (numPrimes < numMaxPrimes) do
	increment = 2
	while (increment <= Math.sqrt(lowerBound)) do
		if (lowerBound % increment == 0)
			compositeCounter += 1
		end
		
		if (compositeCounter >= 2)
			break
		end
		increment += 1
	end
	if (compositeCounter < 1)
		$stderr.print "#{lowerBound} "
		numPrimes += 1
	end
	lowerBound += 1
	compositeCounter = 0
end

#
# Print the finishing time of
# the program
#
finish = Time.now
diff = finish - start
puts "\n#{diff}"
