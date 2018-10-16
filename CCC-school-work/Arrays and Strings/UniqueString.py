"""
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
"""
def uniqueString(aStr):
	""" an elegant pythonic solution"""
	aStr = sorted(aStr)
	for i in aStr:
		if aStr.count(i) > 1:
			return False
		else:
			continue
	return True

aStr = "abcdefg"

print(uniqueString(aStr))
print(aStr)