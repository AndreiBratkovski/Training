#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  lobtain() - take and isolate indicated list out of group of lists,
//              through a careful adjustment of necessary pointers.
//              lobtain() needs to maintain group of lists integrity.
//              
//    behavior: on a NULL Group- do nothing; return NULL.
//              on UNDEFINED Group- return UNDEFINED.
//              on a NULL/UNDEFINED thatList- return as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatList, the one
//              being isolated from the group, is being passed in as a
//              double pointer (we're passing the List pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *lobtain(Group * myListGroup, List ** thatList)
{
	//
	// lobtain function is for obtaining a list from a group, and disconnecting it
	//

	//
	// Initialize a list position and a tmp variable for traversing the group/keeping track
	// of the list position
	//
	sli position;
	List *tmp;

	//
	// If the list group exists and the list to be disconnected exists, program begins
	// searching for which list to obtain.
	//
	if (myListGroup != NULL && myListGroup != UNDEFINED && *thatList != NULL
	    && *thatList != UNDEFINED)
	{

		//
		// If list Group is not empty, program can now obtain a list
		//
		if (myListGroup->initial != NULL
		    && myListGroup->closing != NULL)
		{
			//
			// Obtaining from a one list group.  The list group becomes
			// empty, disconnecting the only list in the group, and pointing
			// it to NULL to avoid a memory leak.
			//
			if (myListGroup->initial == myListGroup->closing)
			{
				myListGroup->initial = NULL;
				myListGroup->closing = NULL;
				(*thatList)->next = NULL;
			}
			//
			// Obtaining from a two list group. List group becomes one list
			// long, but pointer reconfiguring depends on if the list being disconnected
			// is either the initial or closing list.  When program sees which of the two it is,
			// it reconfigures correctly to that condition.
			//
			else if (myListGroup->initial->next ==
				 myListGroup->closing)
			{
				if ((*thatList) == myListGroup->initial)
				{
					myListGroup->initial =
					    myListGroup->closing;
					(*thatList)->next = NULL;
				}
				else if ((*thatList) == myListGroup->closing)
				{
					myListGroup->closing =
					    myListGroup->initial;
					myListGroup->closing->next = NULL;
					(*thatList)->next = NULL;
				}
			}

			//
			// If a list group is 2 lists or greater, program checks first if
			// the list being disconnected is initial or closing. reconfiguring is 
			// different for both edge cases.  The list is disconnected and pointed to 
			// NULL to avoid memory leak.
			//
			else if ((*thatList) == myListGroup->initial)
			{
				myListGroup->initial = (*thatList)->next;
				(*thatList)->next = NULL;
			}
			else if ((*thatList) == myListGroup->closing)
			{
				position = lgetpos(myListGroup, *thatList);
				tmp = lsetpos(myListGroup, (position - 1));
				myListGroup->closing = tmp;
				tmp->next = NULL;

				(*thatList)->next = NULL;
			}

			//
			// If none of the above conditions are met, then program knows to
			// disconnect from somewhere in the middle of the list.  Anywhere that is not
			// an edge case will follow the same programming logic.  Program will re-point
			// list pointers to disconnect thatList.  Once thatList is disconnected, it is pointed to
			// NULL to avoid memory leak.
			//
			else
			{
				position = lgetpos(myListGroup, *thatList);
				tmp = lsetpos(myListGroup, (position - 1));
				tmp->next = (*thatList)->next;
				(*thatList)->next = NULL;
			}
		}
	}

	return (myListGroup);
}
