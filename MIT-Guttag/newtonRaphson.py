"""
Newton Raphson successive approximation of square root
"""

# Find x such that x**2 - k is within epsilon of 0

def newtonRaphson(k):
	epsilon = 0.01
	guess = k/2.0

	while abs(guess*guess - k) >= epsilon:
		guess = guess - (((guess**2) - k)/(2*guess))
		print(guess)

	print('Square root of', k, 'is about', guess)

print(newtonRaphson(400000000))
