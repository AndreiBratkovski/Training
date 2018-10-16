numberofprimes=tonumber(arg[1])

if type(numberofprimes) ~= type(1) then  
	print("Your input was not a number.")
	return
	end 
-- Above is error checking, checks the type of argument 1
testednumber=2
n=0

st_time = os.clock() -- start time of program

while n < numberofprimes do
	m=2
	while m <= testednumber do
		if m == testednumber then
			n = n + 1
			io.stderr:write(testednumber, " ")
		elseif testednumber%m==0 and testednumber~=2 then
			break
		end
		m = m+1
	end
	testednumber = testednumber +1
end
end_time = os.clock()
io.write(string.format("\n%8.4f\n", end_time - st_time))

