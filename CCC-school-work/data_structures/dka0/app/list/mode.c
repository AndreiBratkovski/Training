#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// OPERATION:MODE   - Determine the MODE of info values from a
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

	myList = sortlist(myList, 0);

	int count = 1;
	int highCount = 0;

	//
	// Initialize mode, current, and next.  Current keeps track of current node contents,
	// next keeps track of next node contents.  Mode is the current node that shows up the most
	//
	int mode;

	int current;
	int next;

	//
	// set tmp to beginning of myList
	//
	tmp = myList->engine;

	//
	// traverse list, set current and next values, then compare if they are the same
	// if they are, add to counter.  When a node appears more than a previous mode, add to the counter
	// and update the mode value
	//
	while (tmp->to != NULL)
	{
		current = tmp->contents;
		next = tmp->to->contents;

		if (current == next)
		{
			count++;
		}
		else
		{
			count = 1;
		}

		if (count > highCount)
		{
			highCount = count;
			mode = tmp->contents;
		}
		tmp = tmp->to;
	}

	result = mknode(mode);
	//////////////////////////////////////////////////////////////////
	//
	// Store computed value in info element of result Node.
	//
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
