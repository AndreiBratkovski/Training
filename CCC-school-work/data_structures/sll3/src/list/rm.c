#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// rmlist() - a list library function to deallocate an existing list;
//            care must be taken to ensure any component nodes have
//            been properly disposed of so as to prevent a memory
//            leak. The resulting list will be in a NULL state.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *rmlist(List * myList)
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
	}

	//
	// Finally, free memory of myList and reassign it to NULL,
	// thus deallocating the list.  Return NULL list
	//
	free(myList);
	myList = NULL;

	return (myList);
}
