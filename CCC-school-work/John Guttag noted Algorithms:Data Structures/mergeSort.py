"""
Merge sort is a prototypical divide-and-conquer algorithm. It was invented
in 1945, by John von Neumann, and is still widely used. Like many divide-and-conquer
algorithms, it is most easily described recursively:

1. If the list is of length 0 or 1, it is already sorted
2. If the list has more than one element, split the list into two lists, and
use merge sort to sort each of them.
3. Merge the results
"""
def merge(left, right, compare):
	"""Assumes left and right are sorted lists and
	   compare defines an ordering on the elements.
	   Returns a new sorted (by compare) list containing
	   the same elements as (left + right) would contain. """

	result = []
	i, j = 0, 0
	while i < len(left) and j < len(right):
		if compare(left[i], right[j]):
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
	while (i < len(left)):
		result.append(left[i])
		i += 1
	while (j < len(right)):
		result.append(right[j])
		j += 1
	return result

def mergeSort(L, compare = lambda x, y : x < y):
	"""Assumes L is a list, compare defines an ordering
	   on elements of L
	Returns a new sorted list with the same elements as L"""
	if len(L) < 2:
		return L[:]
	else:
		middle = len(L)//2
		left = mergeSort(L[:middle], compare)
		right = mergeSort(L[middle:], compare)
		return merge(left, right, compare)

L = [2,1,4,5,3]
print(mergeSort(L), mergeSort(L, lambda x, y: x > y))