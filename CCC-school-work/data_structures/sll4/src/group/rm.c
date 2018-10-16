#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// rmgroup() - a group library function to deallocate an existing
//             list group; care must be taken to ensure any component
//             lists have been properly disposed of so as to prevent
//             a memory leak. The resulting group will be in a NULL
//             state following successful processing.
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
Group *rmgroup(Group * oldGroup)
{
	//
	// rmgroup deallocates a list group
	//
	List *tmp;
	List *tmp2;

	//
	// If the list group exists and is not empty, program
	// begins deallocating/clearin the list group
	//
	if (oldGroup != NULL)
	{
		if (oldGroup->initial != NULL)
		{
			//
			// Traverse through group using tmp list pointer and
			// clear each list as we traverse through the group using
			// rmlist function
			//
			tmp = oldGroup->initial;
			while (tmp != NULL)
			{
				tmp2 = tmp;
				tmp = tmp->next;
				rmlist(tmp2);
			}
		}
	}

	//
	// After all of the lists are deallocated and cleared, we free the oldGroup of
	// memory and set it to NULL so that there are no memory leaks
	//
	free(oldGroup);
	oldGroup = NULL;

	return (oldGroup);
}
