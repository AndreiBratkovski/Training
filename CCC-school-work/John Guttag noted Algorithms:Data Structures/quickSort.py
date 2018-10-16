"""
QuickSort in 4 line of code
"""
def quick_sort(a_list):
	if len(a_list) < 2:
		return a_list
	lesser = quick_sort([x for x in a_list[1:] if x <= a_list[0]])
	bigger = quick_sort([x for x in a_list[1:] if x > a_list[0]])
	return sum([lesser, [a_list[0]], bigger], [])

print(quick_sort([1,2,3,3,2,1,4,5,2,2,1,2,3]))