"""
Selection Sort, inefficient swapping sort.  Practiced for understanding
algorithmic design, however, python sorting functions are the way to go here.
"""
def selectionSort(L):
	"""Assumes that L is a list of elements that can be compared using >.
	Sorts L in ascending order """
	suffixStart = 0
	while suffixStart != len(L):
		# look at each element in suffix
		for i in range(suffixStart, len(L)):
			if L[i] < L[suffixStart]:
				# swap position of elements
				L[suffixStart], L[i] = L[i], L[suffixStart]
		suffixStart += 1

	return L

lst = [1,56,4,3,3,2,15,13,5]
print(selectionSort(lst))