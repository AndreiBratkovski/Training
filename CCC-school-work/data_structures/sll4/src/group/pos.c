#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// lgetpos() - a group library utility function to identify the actual
//             position of a given list in an indicated list group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group/list), return negative
//             value (-1), on out-of-bounds condition, return -2
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
sli lgetpos(Group * myListGroup, List * given)
{
	//
	// lgetpos will locate the numerical position in the list group
	// of the given list
	//

	//
	// Initialize position and list counter to keep track of numerical
	// position of list in list group via incrementing during traversal
	// 

	//
	// tmp and tmp2 are temporary list pointers used in list traversal
	//
	sli position = 0;
	int listCounter = 0;
	List *tmp;
	List *tmp2;

	//
	// If the list group is NULL or given is NULL, position is returned as -1
	//
	if (myListGroup == NULL || given == NULL)
	{
		position = -1;
	}
	//
	// Same logic applies to an UNDEFINED listgroup/given list
	//
	if (myListGroup == UNDEFINED || given == UNDEFINED)
	{
		position = -1;
	}

	//
	// If list group/given list exist, then program locates position of list
	//
	if (myListGroup != NULL && myListGroup != UNDEFINED && given != NULL
	    && given != UNDEFINED)
	{
		//
		// Count amount of lists
		//
		tmp2 = myListGroup->initial;
		while (tmp2 != NULL)
		{
			listCounter++;
			tmp2 = tmp2->next;
		}

		//
		// Find position of given list in group
		//
		tmp = myListGroup->initial;
		while (tmp != NULL)
		{
			if (tmp == given)
			{
				break;
			}
			position++;
			tmp = tmp->next;
		}
	}

	//
	// If the entire list group is traversed and the list is not located,
	// return -2 for list position. (doesn't exist)
	//
	if (position == listCounter)
	{
		position = -2;
	}

	return (position);
}

//////////////////////////////////////////////////////////////////////
//
// lsetpos() - a group library utility function to set a list pointer
//             to the list at the indicated position of a group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group or
//             negative/out-of-bounds pos), return NULL.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
List *lsetpos(Group * myListGroup, sli pos)
{
	//
	// lsetpos is a function used to set a tmp list pointer to
	// the given position in a list group
	//
	List *tmp;
	int listCounter = 0;

	//
	// If listGroup is NULL, tmp is NULL
	// no list traversal possible
	//
	if (myListGroup == NULL)
	{
		tmp = NULL;
	}
	//
	// if List group is Undefined, tmp is Undefined.
	// no list traversal possible
	//
	else if (myListGroup == UNDEFINED)
	{
		tmp = UNDEFINED;
	}

	//
	// bulk of programming logic.  If the list group exists, tmp will
	// traverse the list until it finds the given position.
	//
	else if (myListGroup != UNDEFINED && myListGroup != NULL)
	{
		tmp = myListGroup->initial;
		while (tmp != NULL)
		{
			if (listCounter == pos)
			{
				break;
			}
			tmp = tmp->next;
			listCounter++;
		}
	}

	return (tmp);
}
