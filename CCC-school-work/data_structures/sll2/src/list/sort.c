#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **preserved**, and the altered/
//              sorted list (a new list) is what is returned.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, return NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
List *sortlist(List * myList, int mode)
{
	//
	// New List is a copy of the old list.  If List is 1 node, it is already sorted.
	// Declare position, increment, tmpContents, and stop , which will be used in the simple
	// sorting algorithm. Tmp contents holds temporary node contents, increment is used to increment
	// through node "positions" in the list, position is the node position, and stop is the upper bound of
	// limitation within the sorting loop. It usually will indicate the last list element position needed
	// in a sorting iteration
	//
	List *newList = cplist(myList);
	List *newList1;
	Node *newListTmp;

	int position;
	int increment;
	int stop;

	//
	// Check that the List is not EMPTY, NULL, or UNDEFINED, then proceed with program
	//
	if (newList != NULL && newList != UNDEFINED)
	{

		//
		// on invalid mode, Mode is MOD by total modes (3), and continuing
		// If List is 1 node long, list is already sorted and can be returned
		// Else if list is larger than 1 node and not empty, continue program
		//
		if (newList->engine != NULL
		    && newList->engine != newList->caboose)
		{
			if (mode != 0 && mode != 1 && mode != 2)
			{
				mode = mode % 3;
			}

			//
			// Sort List Backwards if more than 1 element
			//
			// Explanation:
			//
			// Create a new list, newlist1.  set position to the end of myList.
			// Then we use obtain to rip the nodes out of the caboose of newList (copied myList), and append
			// them to the caboose of newList1. Once we have moved the nodes into a backwards list
			// newList1... free the memory for newList, and point newList to the newly backwards list
			//      
			if (mode == 2)
			{
				newList1 = mklist();
				position = getpos(myList, myList->caboose);	// Length of list

				while (position != -1)
				{
					newListTmp = newList->caboose;
					newList = obtain(newList, &newListTmp);
					newList1 =
					    append(newList1, newList1->caboose,
						   newListTmp);
					position--;
				}
				rmlist(newList);
				newList = newList1;
			}
			//
			// Sort List least to greatest
			//
			// Explanation:
			//
			// Here, we have a simple sort algorithm, using linked lists to sort from least to greatest. 
			// finding the length of my list, using the position varible, we iterate from 0 to position.
			// (therefore I can use my own version of list iterations, iterating through positions).
			// newListTmp is set to the beginning of new List, which is a copied List,  and position is the highest
			// position we can check in the current sorting iteration.  ( it decreases as the list becomes more sorted).
			// while the position of newListTmp is less than stop, we compare the current newListTmp with the next node and swap them
			// if the next node is less than the current node. Per each iteration, if
			// the position reaches (stop-1), newList starts from the beginning of the list again,
			// and stop is decremented by the current increment. This goes on and iterates over the list length number of times until
			// sorted. 
			// 
			else if (mode == 0)
			{
				position = getpos(myList, myList->caboose);
				position++;	// length of list

				for (increment = 0; increment < position;
				     increment++)
				{
					newListTmp = newList->engine;
					stop = position - increment;

					while (getpos(newList, newListTmp) <
					       stop - 1)
					{
						if (newListTmp->contents >
						    newListTmp->to->contents)
						{
							swapnode(newList,
								 newListTmp,
								 newListTmp->to);
						}
						newListTmp = newListTmp->to;
					}
				}
			}
			//
			// Sort List greatest to least
			//
			// The explanation is the same as the above paragraph, however, instead of swapping when
			// the current node is greater than the next node, we swap the node in the list when the
			// current node is less than the next node, thus iterating until we have a list sorted from greatest contents
			// to smallest contents
			//
			else if (mode == 1)
			{
				position = getpos(myList, myList->caboose);
				position++;	// length of list

				for (increment = 0; increment < position;
				     increment++)
				{
					newListTmp = newList->engine;
					stop = position - increment;

					while (getpos(newList, newListTmp) <
					       stop - 1)
					{
						if (newListTmp->contents <
						    newListTmp->to->contents)
						{
							swapnode(newList,
								 newListTmp,
								 newListTmp->to);
						}
						newListTmp = newListTmp->to;
					}
				}
			}
		}
	}
	//
	// Return sorted list
	//
	return (newList);
}
