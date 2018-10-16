#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  linsert() - add a new list to the given list group before the list
//              at the indicated place. linsert() needs to manage
//              the necessary connections (pointers) to maintain list
//              group integrity, along with ensuring the first and
//              last indicators of the list group remain relevant
//              and up-to-date.
//
//    behavior: on a NULL/UNDEFINED group- return NULL
//              on a NULL/UNDEFINED list-  do nothing; return as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *linsert(Group * myListGroup, List * place, List * newList)
{
	//
	// linsert is a function which inserts a list before a given list
	// in a group
	//

	//
	// Initialize a list position variable and a list tmp variable for traversing
	// the group
	//
	sli position;
	List *tmp;

	//
	// If list group exists, and newList exists, we begin the programming logic
	//
	if (myListGroup != UNDEFINED && myListGroup != NULL && newList != NULL
	    && newList != UNDEFINED)
	{

		//
		// If the list group is empty, the newList is inserted and both the initial/closing
		// pointers point to it, thus creating a one list group
		//
		if (myListGroup->initial == NULL
		    && myListGroup->closing == NULL)
		{
			myListGroup->initial = newList;
			myListGroup->closing = newList;
			newList->next = NULL;
		}

		//
		// If the list group is one list large, insert newList before that one list
		//
		else if (myListGroup->initial == myListGroup->closing)
		{
			newList->next = myListGroup->closing;
			myListGroup->initial = newList;
		}

		//
		// Begining programming programming logic for listgroup that is 2 or more lists large
		//
		// if place given is initial, place the list before the first list in the list group
		//
		else if (place == myListGroup->initial)
		{
			newList->next = myListGroup->initial;
			myListGroup->initial = newList;
		}
		//
		// If the place given is the end of the list, program places new list before the 
		// last list in the list group
		//
		else if (place == myListGroup->closing)
		{
			position = lgetpos(myListGroup, place);
			tmp = lsetpos(myListGroup, (position - 1));
			newList->next = myListGroup->closing;
			tmp->next = newList;
		}

		//
		// The following programming logic is for anywhere in the middle of the list group.
		// pointers of lists are moved around so that the new list can fit within the group
		//
		else if (place != NULL)
		{
			position = lgetpos(myListGroup, place);
			tmp = lsetpos(myListGroup, (position - 1));
			newList->next = tmp->next;
			tmp->next = newList;
		}
	}

	//
	// If the list group is NULL or UNDEFINED, program will return NULL listGroup
	//
	else if (myListGroup == NULL || myListGroup == UNDEFINED)
	{
		myListGroup = NULL;
	}

	return (myListGroup);
}
