#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// OPERATION:RANGE  - Determine the RANGE of info values from a
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

	//
	// Initialize highest, lowest, and range values
	//
	int highest;
	int lowest;
	int range;

	//
	// Sort list in ascending order
	//
	myList = sortlist(myList, 0);

	//
	// Set the highest and lowest values of the list
	//
	highest = myList->caboose->contents;
	lowest = myList->engine->contents;

	//
	// calculate range
	//
	range = highest - lowest;

	//
	// Make result into node with range value.
	//
	result = mknode(range);

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
