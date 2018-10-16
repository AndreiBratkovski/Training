#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality, or the lack
//             thereof.
//
//       note: if difference is initially NULL, care should be taken
//             not to assign any values to it.
//
//             a difference of 0 indicates a NULL or EMPTY list is
//             our point of difference. Any actual list node
//             positions will start from 1 (be aware of this)
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//   examples: a few examples for reference.
//
//             list1:        NULL
//             list2:        NULL
//             code:         CMP_L1_NULL  | CMP_L2_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        EMPTY
//             code:         CMP_L1_EMPTY | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        NULL
//             list2:        EMPTY
//             code:         CMP_L1_NULL  | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        EMPTY
//             list2:        NULL
//             code:         CMP_L1_EMPTY | CMP_L2_NULL
//             difference:   0
//
//             list1:        NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_EMPTY
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        NULL
//             code:         CMP_L2_NULL
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        EMPTY
//             code:         CMP_L2_EMPTY
//             difference:   0
//
//             list1:        2 -> NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_GREATER | CMP_L2_LESS
//             difference:   1
//
//             list1:        1 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 2 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L1_LESS    | CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 3 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_EQUALITY
//             difference:   2
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
//             do not count; navigate by comparison
//
code_t compare(List * myList1, List * myList2, ulli * difference)
{
	//
	// Initialize tmp and tmp2 pointers to traverse list 1 and 2.
	// initialize diff intger to keep track of the difference between
	// lists in position
	//
	Node *tmp = NULL;
	Node *tmp2 = NULL;
	ulli diff = 0;

	//
	// Initialize 2 status codes, one for each list.  Each status code
	// starts at CMP_EQUALITY incase no changes need to be accounted for between    
	// lists
	//
	code_t status1 = CMP_EQUALITY;
	code_t status2 = CMP_EQUALITY;

	//
	// Check if list1 is null or empty. If it is, return NULL/EMPTY status code for
	// list 1. Otherwise, set tmp to list1's engine for it to be traversed and checked upon
	// later
	//
	if (myList1 == NULL)
		status1 = CMP_L1_NULL;
	else if (myList1 == UNDEFINED)
		status1 = CMP_L1_UNDEFINED;
	else if (myList1->engine == NULL)
		status1 = CMP_L1_EMPTY;
	else
		tmp = myList1->engine;

	//
	// Check if list2 is null or empty. If it is, return NULL/EMPTY status code for
	// list 2. Otherwise set tmp to list2's engine for it to be traversed and checked upon later
	//
	if (myList2 == NULL)
		status2 = CMP_L2_NULL;
	else if (myList2 == UNDEFINED)
		status2 = CMP_L2_UNDEFINED;
	else if (myList2->engine == NULL)
		status2 = CMP_L2_EMPTY;
	else
		tmp2 = myList2->engine;

	//
	// If neither lists are empty, iterate through lists, checking the differences between the two of them
	// each iteration where lists are not different will add to the diff counter.  
	//
	while (tmp2 != NULL && tmp != NULL)
	{
		diff++;

		//
		// if List 2 has a greater value at the same position, set status codes to indicate that
		// list 1 is smaller than list 2
		//
		if (tmp->VALUE < tmp2->VALUE)
		{
			status1 = CMP_L1_LESS;
			status2 = CMP_L2_GREATER;
			break;
		}

		//
		// Similarly, if list 1 has a greater value at the same position as list 2, set status codes to
		// indicate that list 1 is greater and list 2 is smaller
		//
		else if (tmp->VALUE > tmp2->VALUE)
		{
			status2 = CMP_L2_LESS;
			status1 = CMP_L1_GREATER;
			break;
		}

		//
		// Move through both lists at the same time by setting each tmp variable to the next position
		//
		tmp = tmp->to;
		tmp2 = tmp2->to;
	}

	//
	// If there were no changes to be found in list1 and list2 is empty, then return a status code
	// indicating that list 1 is greater than list 2
	//
	if ((status1 == CMP_EQUALITY) && (status2 != CMP_L2_EMPTY)
	    && (tmp2 == NULL) && (tmp != NULL))
	{
		status1 = CMP_L1_GREATER;
		diff++;
	}
	//
	// Similarly, if there were no changes to be found in list 2 and list 1 is empty, then return a status code
	// indicating that list2 is greater than list 1
	//
	else if ((status2 == CMP_EQUALITY) && (status1 != CMP_L1_EMPTY)
		 && (tmp2 != NULL) && (tmp == NULL))
	{
		status2 = CMP_L2_GREATER;
		diff++;
	}
	//
	// If difference isn't initially Null, finalize it's value by setting it to our diff integer, checking for list position difference in
	// compare function
	//
	if (difference != NULL)
		*difference = diff;

	//
	// Return combined status codes
	//
	return (status1 | status2);
}
