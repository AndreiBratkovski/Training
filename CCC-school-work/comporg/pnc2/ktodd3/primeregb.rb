
numberofprimes = ARGV[0].to_i


testnumber = 2
test = 0
n = 0

start = Time.now

	while n<numberofprimes do
	m = 2
		while m <= testnumber do
			if m == testnumber
				n += 1 
#				$stderr.puts "%d " % testnumber
				$stderr.printf "%d " % testnumber
			elsif testnumber % m == 0 && testnumber != 2
				break
			end
			m+=1
		end
	testnumber += 1
	end
puts
finish = Time.now
delta = finish - start
puts "%8.4f\n" % delta
