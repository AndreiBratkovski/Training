import sys
import time



def is_intstring(s):
	try:
		int(s)
		return True
	except ValueError:
		return False

for arg in sys.argv[1:]:
	if not is_intstring(arg):
		sys.exit("All arguments must be integers. Exit.")
#above is the error checking for the argument.
numberofprimes = int(sys.argv[1])
testednumber=2
test=0

start = time.time()

n = 0
while n < numberofprimes:
	test=0
	m=2
	while m <= testednumber:
		if m == testednumber:
			n += 1
			sys.stderr.write("%d " % testednumber)
		elif testednumber%m==0 & testednumber!=2:
			break
		m += 1
	testednumber += 1

end = time.time()
total = end - start
sys.stdout.write("\n%8.4lf\n" % total)
