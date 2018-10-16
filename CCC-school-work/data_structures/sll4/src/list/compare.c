#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality (or the lack
//             thereof), as well as the position of difference.
//
//       note: if pos is initially NULL, care should be taken not to
//             assign any values to it.
//
//             a pos of 0 indicates a NULL or EMPTY list is our 
//             point of difference. Any actual list node positions
//             will start from 1 (be aware of this difference from
//             setpos()/getpos()).
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//             if a list is UNDEFINED, use that specific code
//
//   examples: a few examples for reference.
//
//             list1: NULL
//             list2: NULL
//             code:  CMP_L1_NULL  | CMP_L2_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: EMPTY
//             code:  CMP_L1_EMPTY | CMP_L2_EMPTY
//             pos:   0
//
//             list1: NULL
//             list2: EMPTY
//             code:  CMP_L1_NULL  | CMP_L2_EMPTY
//             pos:   0
//
//             list1: EMPTY
//             list2: NULL
//             code:  CMP_L1_EMPTY | CMP_L2_NULL
//             pos:   0
//
//             list1: NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_EMPTY
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: NULL
//             code:  CMP_L2_NULL
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: EMPTY
//             code:  CMP_L2_EMPTY
//             pos:   0
//
//             list1: 2 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_GREATER | CMP_L2_LESS
//             pos:   1
//
//             list1: 1 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 2 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_L1_LESS    | CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 3 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_EQUALITY
//             pos:   2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
uc compare(List * myList1, List * myList2, ulli * pos)
{
	uc statusCode;
	Node *tmp;
	Node *tmp2;
	int checkTrigger = 0;

	//////////////////////////////////////////////////////////////////////
	//
	// if both lists are NULL
	//
	if (myList1 == NULL && myList2 == NULL)
	{
		statusCode = CMP_L1_NULL | CMP_L2_NULL;
	}

	//
	// if List 1 is not NULL and List2 is NULL
	//
	else if (myList1 != NULL && myList2 == NULL)
	{
		//
		// if List1 is empty and List2 is NULL
		//
		if (myList1->engine == NULL)
		{
			statusCode = CMP_L1_EMPTY | CMP_L2_NULL;
		}
		//
		// if List1 is NOT empty and List2 is NULL
		//
		else if (myList1->engine != NULL)
		{
			statusCode = CMP_L2_NULL;
		}
	}

	////////////////////////////////////////////////////////////////////////
	//
	// if List 1 is NULL and List 2 is NOT NULL
	//
	else if (myList1 == NULL && myList2 != NULL)
	{
		//
		// if List 2 is empty and List1 is NULL
		//
		if (myList2->engine == NULL)
		{
			statusCode = CMP_L1_NULL | CMP_L2_EMPTY;
		}
		//
		// if List 2 is not empty and List1 is NULL
		//
		else if (myList2->engine != NULL)
		{
			statusCode = CMP_L1_NULL;
		}
	}

	/////////////////////////////////////////////////////////////////
	// if List1 and List 2 are NOT NULL
	//
	else if (myList1 != NULL && myList2 != NULL)
	{
		//
		// if BOTH List1 and List2 are EMPTY
		//
		if (myList1->engine == NULL && myList2->engine == NULL)
		{
			statusCode = CMP_L1_EMPTY | CMP_L2_EMPTY;
		}
		//
		// if List1 is EMPTY and List2 is populated
		//
		else if (myList1->engine == NULL && myList2->engine != NULL)
		{
			statusCode = CMP_L1_EMPTY;
		}
		//
		// if List1 is populated and List2 is empty
		//
		else if (myList1->engine != NULL && myList2->engine == NULL)
		{
			statusCode = CMP_L2_EMPTY;
		}

		///////////////////////////////////////////////////////////////
		//
		// Finally, if both List1 and List 2 are populated,
		// this is where some control flow and logic is necessary
		// to determine status codes
		//
		else if (myList1->engine != NULL && myList2->engine != NULL)
		{
			tmp = myList1->engine;
			tmp2 = myList2->engine;
			if (pos != NULL && pos != 0)
			{
				(*pos) = 1;
			}

			//
			// Iterate through list and compare contents
			// until one or both lists hits NULL (end of List)
			//
			while (tmp->to != NULL || tmp2->to != NULL)
			{
				if (tmp->contents != tmp2->contents)
				{
					checkTrigger++;
					break;
				}
				tmp = tmp->to;
				tmp2 = tmp2->to;

				//
				// increment position on each element of comparison
				//
				if (pos != NULL && pos != 0)
				{
					(*pos)++;
				}

				//
				// break out of loop if hitting NULL in either list(top driven)
				//
				if (tmp->to == NULL || tmp2->to == NULL)
				{
					break;
				}
			}

			///////////////////////////////////////////////////////////////////////////
			//
			// Checking for list equality
			//
			if (tmp->to == NULL && tmp2->to == NULL)
			{
				if (tmp->contents == tmp2->contents
				    && checkTrigger == 0)
				{
					statusCode = CMP_EQUALITY;
				}
			}
			//
			// If list contents differ during comparison, check which list is
			// greater and return status code
			//
			else if (checkTrigger == 1)
			{
				if (tmp->contents > tmp2->contents)
				{
					statusCode =
					    CMP_L1_GREATER | CMP_L2_LESS;
				}
				else if (tmp->contents < tmp2->contents)
				{
					statusCode =
					    CMP_L1_LESS | CMP_L2_GREATER;
				}
			}

			/////////////////////////////////////////////////////////////////////////////
			//
			// if myList2 is larger than myList1, check which element contents are larger
			//
			else if (tmp->to == NULL && tmp2->to != NULL
				 && checkTrigger == 0)
			{
				//
				// if MyList2 contents are greater or the same, but myList2 is larger
				// status code of myList2 greater returned, followed by position 
				//
				if (tmp2->contents >= tmp->contents)
				{
					statusCode = CMP_L2_GREATER;
					(*pos)++;
				}

				//
				// if myList2 is larger, but mylist1 contents are greater,
				// return position and mylist1 greater status code
				//
				else if (tmp2->contents < tmp->contents)
				{
					statusCode = CMP_L1_GREATER;
					(*pos)++;
				}
				//
				// If the contents of both lists have remained the same except the last of myList2,
				//
				else if (tmp->contents == tmp2->contents
					 && checkTrigger == 0)
				{
					statusCode =
					    CMP_L1_GREATER | CMP_L2_LESS;
				}
			}

			/////////////////////////////////////////////////////////////////////////////
			//
			// if MyList1 is larger than MyList2, check which element contents are larger
			//
			else if (tmp->to != NULL && tmp2->to == NULL)
			{
				//
				// Check if myList1 contents are equal to myList2 contents
				// if so, Mylist2 is greater in current position
				//
				if (tmp->contents == tmp2->contents
				    && checkTrigger == 0)
				{
					statusCode =
					    CMP_L1_LESS | CMP_L2_GREATER;
				}
				//
				// If myList1 contents are greater than or equal to mylist2 contents,
				// return myList1 greater status code
				//
				else if (tmp->contents >= tmp2->contents)
				{
					statusCode = CMP_L1_GREATER;
					(*pos)++;
				}
				//
				// if myList1 contents are less than mylist2 contents,
				// return myList2 greater status code
				//
				else if (tmp->contents < tmp2->contents)
				{
					statusCode = CMP_L2_GREATER;
					(*pos)++;
				}
			}
		}
	}
	return (statusCode);
}
