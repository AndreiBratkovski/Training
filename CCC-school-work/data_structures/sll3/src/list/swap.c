#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own initial and closing pointers, along with
//              connectivity between the nodes from the start to end
//              of the list).
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
//    behavior: on a NULL list- do nothing: return NULL
//              on UNDEFINED list- return list as is
//              on an EMPTY list- do nothing: return list unchanged
//              on a NULL/invalid nodes to swap- do nothing: return
//                  the list unchanged
//
//        note: where applicable, make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *swapnode(List * myList, Node * item1, Node * item2)
{
	//
	// Declaring variables for the position of item 1 and item 2
	// Declaring tmp Contents so that we can swap contents of item 1 and item 2
	// without losing the value of either while reassigining their values
	//
	int position1;
	int position2;
	Node *tmp;

	//
	// Check that list is not NULL, UNDEFINED, and that item1/2 are not NULL/invalid.
	// Otherwise, do nothing and return list as NULL or unchanged.  If the list is NOT empty and
	// does exist, continue with program.
	//
	if (myList != NULL && myList != UNDEFINED && item1 != NULL
	    && item2 != NULL)
	{
		//
		// If List is not empty, go through programming logic
		//
		if (myList->engine != NULL)
		{
			//
			// Set position of item1 and item2
			// of myList to prepare for swapping at those
			// positions
			//      
			position1 = getpos(myList, item1);
			item1 = setpos(myList, position1);

			position2 = getpos(myList, item2);
			item2 = setpos(myList, position2);

			//
			// Before swapping, we need to make sure that
			// the positions aren't the same, because then a swap
			// isn't necessary
			//
			if (position1 != position2 )
			{
				//
				// If swapping, copy both item 1 and 2, then append them at the
				// earlier indicated positions. Afterwards, obtain the old items from
				// myList, therefore successfully swapping nodes
				//
				tmp = mknode(item2->contents);
				myList = append(myList, item1, tmp);

				tmp = mknode(item1->contents);
				myList = append(myList, item2, tmp);

				myList = obtain(myList, &item1);
				myList = obtain(myList, &item2);

			}
		}
	}
	//
	// return swapped list, or unchanged/NULL list
	//
	return (myList);
}
