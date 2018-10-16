--[[ prime number calculator 
--
--	to run, type: lua5.3 primeregba.lua QTY
--		where QTY is how many primes you want to calculate
--]]

-- check arguments and see if qty is positive
if #arg == 1 then
	qty = tonumber(arg[1])

	if qty < 0 then
		io.write("Must provide positive quantity!\n")
		os.exit()
	end
else
	io.write("USAGE: Must provide quantity as command line argument!\n")
	os.exit()
end

st_time = os.clock() -- start time

num_primes = 0 -- number of primes to calculate
num = 2 -- number to start checking for primality 
factor = 2 -- factor to test num
prime = 1 -- is a number prime or not

-- loop until we find all the primes we want
while num_primes < qty do
	-- check up to square root of num
	while factor*factor <= num do
		-- if factor divides evenly, num is composite
		if num%factor == 0 then
			prime = 0
			break
		end

		factor = factor + 1
	end
	-- if prime, increment num_primes and print num
	if prime == 1 then
		io.stderr:write(string.format("%d ", num))
		num_primes = num_primes + 1
	else
		prime = 1
	end

	num = num +  1 -- go to next number
	factor = 2 -- restore to default
end

io.stderr:write("\n")

end_time = os.clock() -- end time

io.write(string.format("%8.4f\n", end_time - st_time)) -- print elapsed time
