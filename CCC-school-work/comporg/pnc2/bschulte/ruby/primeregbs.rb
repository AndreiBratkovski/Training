#!/usr/bin/ruby
##############

require "benchmark"

if ARGV.length < 1
	puts "Too Few Arguments"
	exit
elsif Integer(ARGV[0]) <= 1
	puts "UpperBound must be at least 2"
	exit
else
	upBound=Integer(ARGV[0])
end

divBy=2
i=3
num=2

time = Benchmark.realtime do

$stderr.printf "2 3 "

while num != upBound
	sqt=Integer(Math.sqrt(i))
	mod=i%divBy
	
	if mod != 0
		if divBy != sqt
			divBy+=1
		elsif divBy==sqt
			$stderr.printf "%d ", i
			i+=1
			num+=1
			divBy=2
		end	
	else
		i+=1
		divBy=2
	end	
end



end
$stdout.printf "%8.4f\n", time

