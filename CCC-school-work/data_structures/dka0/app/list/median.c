#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// OPERATION:MEDIAN - Determine the MEDIAN of info values from a
//                    list of nodes.
//
int main()
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare and initialize variables
	//
	List *myList = NULL;
	Node *result = NULL;
	int index = 0;

	char data[] = { 73, 86, 96, 47, 56, 99, 103, 92,
		91, 47, 95, 84, 37, 73, 59, 61,
		104, 42, 73, 97, 98, 79, 78, 16,
		52, 39, 26, 13, 73, 79, 24, 78
	};

	//////////////////////////////////////////////////////////////////
	//
	// Create the list, fill it with values
	//
	myList = mklist();
	for (index = 0; index < 32;)
		myList = append(myList, myList->caboose, mknode(data[index++]));

	Node *tmp;

	//
	// initialize median variable to store median value
	//
	int median;

	//
	// sort list in ascending order
	//
	myList = sortlist(myList, 0);

	//
	// If list length (index in this case) is even, average 2 middle elements for median
	//
	if (index % 2 == 0)
	{
		//
		// Reposition index down to 31 for correct positional calculations afterwards
		//
		index--;
		tmp = setpos(myList, (index / 2));
		median = tmp->contents;
		tmp = setpos(myList, ((index / 2) + 1));
		median += tmp->contents;
		median = median / 2;
	}

	//
	// If list length is odd, simply set median to middle value
	//
	else if (index % 2 != 0)
	{
		index--;
		tmp = setpos(myList, (index / 2 + 1));
		median = tmp->contents;
	}
	//
	// Make result node with median value
	//
	result = mknode(median);

	//////////////////////////////////////////////////////////////////
	//
	// Store computed value in info element of result Node.
	//
	if (result != NULL)
		fprintf(stdout, "Result of OPERATION is: %hhu\n",
			result->contents);

	//////////////////////////////////////////////////////////////////
	//
	// Clean up
	//
	myList = rmlist(myList);
	return (0);
}
