"""
Fibonacci factory, efficient fibonacci sequence
adding up all even fib numbers up to 4 million
"""
class FiboFactory(object):
	current = 1
	previous = 0

	def getNext(self):
		nextNum = self.current + self.previous
		self.previous = self.current
		self.current = nextNum
		return nextNum

factory = FiboFactory()
runningTotal = 0

while True:
	nextNum = factory.getNext()
	if nextNum >= 4000000:
		break
	print(nextNum)
	if nextNum % 2 == 0:
		runningTotal += nextNum

print(runningTotal)