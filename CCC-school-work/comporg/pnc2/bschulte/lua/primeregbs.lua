require "os"
require "io"
require "string"

local divBy, i, num = 2, 3, 2
local upBound = tonumber(arg[1])

start = os.clock()

io.stderr:write("2 3 ")

while num ~= upBound do
	local sqt = math.sqrt(i)
	local mod = i%divBy
	sqt=math.floor(sqt)
	if mod ~= 0 then
		if divBy ~= sqt then
			divBy=divBy+1
		elseif divBy==sqt then
			io.stderr:write(i)
			io.stderr:write(" ")
			i=i+1
			num=num+1
			divBy=2
		end
	else
		i=i+1
		divBy=2
	end
end


stop = os.clock()

io.write(string.format("\n%8.4f\n", stop - start))
