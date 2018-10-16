#!/usr/bin/python
import sys
import time

# printf function top STDERR
def printferr(format, *args):
    sys.stderr.write(format % args)
# printf function to STDOUT
def printfout(format, *args):
    sys.stdout.write(format % args)

# Newtons square root
def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

# make integer of first command line argument
if len(sys.argv) < 2:
    print("Error: incorrect number of arguments!")
    sys.exit(1)
else:
    qty = int(sys.argv[1])

start_time = time.time()
    
count = 0
number = 1 
check = 1

while count < qty:
    number += 1
    factor = 2 
    check = 1
    sqrt = isqrt(number)
    while factor <= sqrt:
        mod = number%factor
        if mod == 0:
            check = 0
            break
        factor += 1
    if check == 1:
        printferr("%d ", number)
        count += 1
printferr("\n")
printfout("%8.4lf\n", time.time() - start_time)
