#!/usr/bin/lua5.3

-- comments like this

--[[multi line
comments like this]]

number = 1 
count  = 0 
factor = 2 
check  = 1

--[[if arg[1] then
    print("Error: invalid arguments\n")
else]]
qty = tonumber(arg[1])
--end

local time = os.clock()
while (count < qty) do
    number = number + 1
    num = math.sqrt(number) --find sqrt / can be decimal
    sqrt = math.floor(num)  --find the largest int smaller than or equal to (drops decimal)
    check = 1
    factor = 2
    while (factor <= sqrt) do
        mod = math.fmod(number,factor)
        if mod == 0 then
            check = 0
            break
        end
        factor = factor + 1
    end
    if check == 1 then
        io.stderr:write(number, " " )
        count = count + 1
    end
end
print()
print(string.format("%8.4f", os.clock() - time)) 
