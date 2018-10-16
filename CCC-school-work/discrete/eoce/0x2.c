///////////////////////////////////////////////////
//
// Andrei Bratkovski - 0x2 discrete - Sort Buffet
//
//////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
// Prototype functions for sorts and
// swapping functionality 
//

void printArray(int[], int);
void swap(int *, int *);
void bubbleSort(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void quicksort(int[], int, int);
void shellSort(int[], int);

//
// Driving the examples in main for readability, experimenting with 
// each sorting algorithm via function calls
//
int main()
{
//
// Starting with an allocated array of 10 elements, with integers randomly
// assigned in each variation
//
	int testArray[10];

//
// if we divide the size of all the elements combined by the size of each element,
// we get the length of the array
//
	int length = sizeof(testArray) / sizeof(testArray[0]);

//
// Each variation of sort will be performed through an iteration through a loop and a switch.
//
	int increment;
	int variation = 0;

	srand(time(NULL));	// seed number generator
	// randomly assign integers 1-100 to array

	srand(time(NULL));

	for (; variation <= 3; variation++)
	{
		//
		// Reset the array to be unsorted and random for each iteration
		//
		for (increment = 0; increment < 10; increment++)
			testArray[increment] = rand() % 100 + 1;

		switch (variation)
		{
			//
			// Bubble Sort
			//
		case 0:
			fprintf(stdout, "Original Array: ");
			printArray(testArray, length);
			bubbleSort(testArray, length);
			fprintf(stdout, "Bubble sorted: ");
			printArray(testArray, length);
			break;

			//
			// Merge Sort
			//
		case 1:
			fprintf(stdout, "Original Array: ");
			printArray(testArray, length);
			mergeSort(testArray, 0, length - 1);
			fprintf(stdout, "Merge sorted: ");
			printArray(testArray, length);
			break;
			//
			// Quick Sort
			//
		case 2:
			fprintf(stdout, "Original Array: ");
			printArray(testArray, length);
			quicksort(testArray, 0, length - 1);
			fprintf(stdout, "Quicksorted: ");
			printArray(testArray, length);
			break;
			//
			// Shell Sort
			//
		case 3:
			fprintf(stdout, "Original Array: ");
			printArray(testArray, length);
			shellSort(testArray, length);
			fprintf(stdout, "Shell Sorted: ");
			printArray(testArray, length);

		default:
			break;
		}
		fprintf(stdout, "\n");	// carriage return to separate answers
	}
	return 0;
}

//
// Swap two indexes in an array that are being pointed at
// Used in most sorting algorithms when iterating through
// a list of values
//
// Side note : Ahh the beauty of pointers, our ability to simply
// point at the memory we want.  If only the world could understand its beauty
// as it is abstracted away from literally every popular programming language
// nowadays
//
void swap(int *val1, int *val2)
{
	int tmp = *val1;

	*val1 = *val2;
	*val2 = tmp;
}

//
// bubble Sort is simply a nested for loop, checking the values between
// neighboring elements or nodes in an array, then swapping them based on
// their size
//
void bubbleSort(int array[], int length)
{
	int increment1;
	int increment2;

	for (increment1 = 0; increment1 < length - 1; increment1++)
	{
		for (increment2 = 0; increment2 < length - 1; increment2++)
		{
			if (array[increment2] > array[increment2 + 1])
				swap(&array[increment2],
				     &array[increment2 + 1]);
		}
	}
}

//
// Merge sort is a divide and conquer algorithm which separates
// an array into multiple partitions and sorts it. This is a
// divide and conquer approach
//
void merge(int array[], int left, int middle, int right)
{
	//
	// merge is a function to merge all of the sorted sub arrays
	// we have three incrementing integers, and integers representing
	// array sublengths
	//
	int increment1, increment2, increment3;
	int subLengthL = middle - left + 1;
	int subLengthR = right - middle;

	//
	// Create A left an right array for holding the data in both left/right
	// subarrays being merged
	//
	int leftArray[subLengthL];
	int rightArray[subLengthR];

	//
	// Copy over data into left and right temporary subarrays
	//
	for (increment1 = 0; increment1 < subLengthL; increment1++)
		leftArray[increment1] = array[left + increment1];
	for (increment2 = 0; increment2 < subLengthR; increment2++)
		rightArray[increment2] = array[middle + 1 + increment2];

	//
	// Merge the temp arrays
	//      
	increment1 = 0;		// first index of first sub array
	increment2 = 0;		// first index of second sub array
	increment3 = left;	// first index of merged sub array

	while (increment1 < subLengthL && increment2 < subLengthR)
	{
		if (leftArray[increment1] <= rightArray[increment2])
		{
			array[increment3] = leftArray[increment1];
			increment1++;
		}
		else
		{
			array[increment3] = rightArray[increment2];
			increment2++;
		}
		increment3++;
	}
	//
	// Copy over remaining elements of leftArray
	//
	while (increment1 < subLengthL)
	{
		array[increment3] = leftArray[increment1];
		increment1++;
		increment3++;
	}
	//
	// Copy over remaining elements of rightArray
	//
	while (increment2 < subLengthR)
	{
		array[increment3] = rightArray[increment2];
		increment2++;
		increment3++;
	}
}

//
// merge sort function which splits up the arrays into partions and
// calls the merge function to merge them
//
void mergeSort(int array[], int left, int right)
{
	if (left < right)
	{
		// 
		// sets the middle index to split array in halves
		// 
		int middle = left + (right - left) / 2;

		// Sorting both halves
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

//
// Recursive quicksort function, another divide and
// conquer algorithm which takes in the first and last
// index of a list, creating a pivot by choice ( first in our case )
// subdividing the arrays, and sorting them
//
void quicksort(int array[], int first, int last)
{
	int increment1, increment2, pivot, tmp;

	if (first < last)
	{
		// set the pivot to the first element
		pivot = first;
		increment1 = first;
		increment2 = last;

		//
		// subdivide into arrays where values less
		// than the pivot are in the first sub array, vice versa
		//
		while (increment1 < increment2)
		{
			while (array[increment1] <= array[pivot]
			       && increment1 < last)
				increment1++;
			while (array[increment2] > array[pivot])
				increment2--;

			if (increment1 < increment2)
			{
				tmp = array[increment1];
				array[increment1] = array[increment2];
				array[increment2] = tmp;
			}
		}
		//
		// swapping array elements, using temp variable to
		// hold array contents
		//
		tmp = array[pivot];
		array[pivot] = array[increment2];
		array[increment2] = tmp;

		//
		// recursive sorting calls to sort the sub arrays
		//
		quicksort(array, first, increment2 - 1);
		quicksort(array, increment2 + 1, last);
	}
}

//
// Shell sort - an insertion sort which swaps elements that
// are far away from eachother
//
void shellSort(int array[], int length)
{
	int gap;
	int increment1;

	//
	// Start with large gap, which is half of array length,
	// and reduce the gap over time
	//
	for (gap = length / 2; gap > 0; gap /= 2)
	{
		// gapped insertion sort
		for (increment1 = gap; increment1 < length; increment1 += 1)
		{
			//
			// add the array element to elements that are
			// gap sorted, save value in temp variable
			//
			int temp = array[increment1];

			//
			// shift previous gap sorted elements until location for
			// temp value is found
			//
			int increment2;

			for (increment2 = increment1;
			     increment2 >= gap
			     && array[increment2 - gap] > temp;
			     increment2 -= gap)
				array[increment2] = array[increment2 - gap];

			// place the original array[increment] into its
			// correct location
			array[increment2] = temp;
		}
	}
}

//
// Function which simply prints any array in order
//
void printArray(int array[], int length)
{
	int increment;

	for (increment = 0; increment < length; increment++)
		fprintf(stdout, "%d ", array[increment]);

	fprintf(stdout, "\n");
}
