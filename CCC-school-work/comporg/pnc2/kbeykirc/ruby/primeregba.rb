# prime number calculation thingy, now in ruby 
#
# to run, type: ruby primeregba.rb QTY
# 	where QTY is the number of primes to calculate

require "benchmark" # for timing

# check arguments
if ARGV.size == 1
	qty = ARGV[0].to_i
	
	if qty < 0
		abort("Must provide positive quantity!\n")
	end
else
	abort("Must provide one argument: quantity!\n")
end

# begin timing
time = Benchmark.realtime do
	num_primes = 0 # no primes have been found yet
	num = 2 # start checking numbers at 2
	factor = 2 # start checking factors at 2
	prime = 1 # number is prime until found to be composite
	
	# keep checking numbers until we find enough primes
	while num_primes < qty
		# check each number up to its square root
		while factor*factor <= num		
			# if number has a factor besides itself and 1,
			# it is composite
			if num%factor == 0
				prime = 0
				break
			end
			# go to next factor
			factor += 1
		end
		# if prime, print the number
		if prime == 1
			$stderr.printf "%d ", num
			num_primes += 1
		# otherwise restore to default
		else
			prime = 1
		end
		# restore factor and go to next number
		factor = 2
		num += 1
	end
	# a nice space for formatting
	$stderr.printf "\n"
end

$stdout.printf "%8.4f\n", time # print timing data

