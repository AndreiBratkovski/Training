""" 2nd implementation of merge sort
Merge sort does log n merge steps because each
merge step doubles the list size.

It does n work for each merge step because it must look at
every item. Simpler looking algorithm for merge sort.

So it runs in O(n log n)
"""

def merge_sort(A):
	merge_sort2(A, 0, len(A)-1)
	return A

def merge_sort2(A, first, last):
	if first < last:
		middle = (first + last)//2
		merge_sort2(A, first, middle)
		merge_sort2(A, middle+1, last)
		merge(A, first, middle, last)

def merge(A, first, middle, last):
	L = A[first:middle]
	R = A[middle:last+1]
	L.append(9999999)
	R.append(9999999)
	i = j = 0
	for k in range(first, last+1):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

lst = [44,33,77,22,33,44,88]
print(merge_sort(lst))

