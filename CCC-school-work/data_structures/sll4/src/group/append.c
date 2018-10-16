#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  lappend() - add a new list to the given list group after the list
//              at the indicated place. lappend() needs to manage
//              the necessary connections (pointers) to maintain list
//              group integrity, along with ensuring initial and
//              closing indicators of the list group remain relevant
//              and up-to-date.
//
//    behavior: on a NULL/UNDEFINED group- return NULL
//              on a NULL/UNDEFINED newList- return group as is
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *lappend(Group * myListGroup, List * place, List * newList)
{
	//
	// lappend is a function used to append a list to a list group
	//
	List *tmp;
	sli position;

	//
	// Begin program logic if a list group exists and the new list also exists
	//
	if (myListGroup != UNDEFINED && myListGroup != NULL && newList != NULL)
	{
		//
		// Append a new list to an empty group.  New list becomes the initial/closing list.
		//
		if (myListGroup->initial == NULL
		    && myListGroup->closing == NULL)
		{
			myListGroup->initial = newList;
			myListGroup->closing = newList;
			newList->next = NULL;
		}
		//
		// Append new list to 1 list sized list group. new list becomes new closing
		//
		else if (myListGroup->initial == myListGroup->closing)
		{
			myListGroup->initial->next = newList;
			myListGroup->closing = newList;
		}
		//
		// Append on two or greater list amount group
		// If place is initial list, rearrange list group to include new List
		// after initial position
		//
		else if (place == myListGroup->initial)
		{
			newList->next = myListGroup->initial->next;
			myListGroup->initial->next = newList;
		}
		//
		// Append on two or greater list amount group
		// if place is closing list, rearrange list group to
		// include new list at end of the list
		//
		else if (place == myListGroup->closing)
		{
			position = lgetpos(myListGroup, place);
			tmp = lsetpos(myListGroup, position);
			tmp->next = newList;
			myListGroup->closing = newList;
		}
		//
		// Append a list somewhere in the middle of the group
		// If the place is anywhere in the middle of the list group
		// program points prevous list to newlist, and new list points to 
		// the next list, thus adding a list after the specified position
		//
		else if (place != NULL)
		{
			position = lgetpos(myListGroup, place);
			tmp = lsetpos(myListGroup, position);
			newList->next = tmp->next;
			tmp->next = newList;
		}
	}

	return (myListGroup);
}
