"""
clean implementation of quicksort
"""

def quicksort(array):
	less = []
	equal = []
	greater = []

	if len(array) > 1:
		pivot = array[0]
		for x in array:
			if x < pivot:
				less.append(x)
			elif x == pivot:
				equal.append(x)
			else:
				greater.append(x)

		return quicksort(less) + equal + quicksort(greater) # joining lists

	else:
		return array
		# with one element in the array, return the array

lst = [12,4,5,6,7,3,1,15]
print(quicksort(lst))