#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// clearlist() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               clearlist().
//
//     behavior: on error, return NULL.
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
List *clearlist(List * myList)
{
	// your implementation here (please remove this comment when done)
	Node *tmp;
	Node *tmp2;

	//
	// If myList is empty or NULL, skip this loop and
	// return a NULL list.  Else, iterate through the list with 
	// tmp and tmp2, then free each node of the list
	//
	if (myList != NULL)
	{
		if (myList->engine != NULL)
		{

			tmp = myList->engine;
			while (tmp != NULL)
			{
				tmp2 = tmp;
				tmp = tmp->to;
				free(tmp2);
			}
		}
		//
		// After clearing/deallocating the list, return
		// a new, empty list
		//
		myList = mklist();
	}

	return (myList);
}
