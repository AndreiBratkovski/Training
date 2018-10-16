#!/usr/bin/ruby

# comments are using the pound key (hashtag for the young kids)
if ARGV.empty?
    puts "Error: No quantity given!\n"
    exit
end

number = 1
factor = 2
count  = 0
check  = 1
qty    = ARGV[0].to_i #to_i simply to integer otherwise it is a string (starts at 0 instead of 1)

time_start = Time.now

while count < qty
    number += 1
    check   = 1
    factor  = 2
    sqr = Math.sqrt(number).floor # finds square root and then floors it to the lower whole integer
    while factor <= sqr             # use the sqrt to find prime potential
        if number % factor == 0
            check = 0
            break 
        end
    factor += 1
    end
    if check == 1
        $stderr.printf("%d ", number)
        count += 1
    end
end
puts "\n"
printf("%8.4f\n", Time.now - time_start)
