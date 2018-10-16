"""Bubble Sort"""
# slow algorithm, like selection sort
# only good in small data sets

def bubbleSort(myList):
	for i in range(0, len(myList) - 1):
		for j in range(0, len(myList) - 1):
			if myList[j] > myList[j+1]:
				myList[j], myList[j+1] = myList[j+1], myList[j]
	return myList

theList = ['b', 'd', 'f', 'a', 'c', 'e']
print(bubbleSort(theList))