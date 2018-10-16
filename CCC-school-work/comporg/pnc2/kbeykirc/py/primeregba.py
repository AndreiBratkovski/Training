# prime number calculation thingy, now in python 
#
# to run, type: python primeregba.py QTY 
#   where QTY is the number of primes to display 

import sys
import time

# check arguments 
if len(sys.argv) == 2:
    
    qty = int(sys.argv[1]) # set quantity 

    if(qty < 0):
        sys.stderr.write("Argument must be positive!\n")
        sys.exit
else:
    sys.stderr.write("Must provide one argument: quantity!\n")
    sys.exit

num_primes = 0 # number of primes 
num = 2 # number to start checking at
factor = 2 # factor to start checking at 
prime = 1 # is a number prime or not?
 
start = time.time() # begin timing 

# loop to find primes
while num_primes < qty:
    # check up until square root of number for possible factors
    while factor*factor <= num:
        # if a factor is found, number isn't prime
        if num%factor == 0:
            prime = 0
            break
        factor += 1

    # if prime, print it 
    if prime:
        sys.stderr.write("%d " % num) 
        num_primes += 1

    # restore defaults and go to next number
    prime = 1
    factor = 2
    num += 1

sys.stderr.write("\n") # a nice new line

end = time.time() # stop timing

total = end - start # calculate elapsed time

# print timing info 
sys.stdout.write("%8.4lf\n" % total)
