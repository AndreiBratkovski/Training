import time
import sys
import math

if(len(sys.argv) >= 2):
	if(int(sys.argv[1])<=0):
		print("Bad Argument- must be greater than 0", file=sys.stderr)
		exit(0)
else:
	print("No Upper Bound", file=sys.stderr)
	exit(0)

upBound=int(sys.argv[1])
divBy=2
i=3
num=2

start = time.time()

print("2 3 ", file=sys.stderr, end='')

while(num!=upBound):
	sqt=int(math.sqrt(i))
	mod=i%divBy

	if(mod!=0):
		if(divBy!=sqt):
			divBy+=1
		elif (divBy==sqt):
			print("%d " % i, file=sys.stderr, end='')
			i+=1
			num+=1
			divBy=2
		else:
			print("%d " % i, file=sys.stderr, end='')
			i+=1
			num+=1
			divBy=2
	else:
		i+=1
		divBy=2



end = time.time()
print("%8.4f" % (end-start))
