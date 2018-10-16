"""
Code golfed implementation of quicksort using list comprehensions
"""

def quicksort(arr):
	""" Quicksort a list

	:type arr: list
	:param arr: List to sort
	:returns: list -- Sorted list
	"""
	if not arr:
		return []

	pivots = [x for x in arr if x == arr[0]]
	lesser = quicksort([x for x in arr if x < arr[0]])
	greater = quicksort([x for x in arr if x > arr[0]])

	return lesser + pivots + greater

lst = [7,4,2,7,3,1,1,9,0,3,2]
print(quicksort(lst))
