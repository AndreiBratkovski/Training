#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// getpos() - a list library utility function to identify the actual
//                      position of a given node in an indicated list.
//
//        note: Indexing of the list starts from 0
//
//  behavior: on error (NULL/UNDEFINED list or given node), return
//                      negative value (-1), on out-of-bounds condition,
//                      return -2
//
//                      you are to have only ONE return statement for this
//                      entire function. Change the existing one as needed.
//
int getpos(List * myList, Node * given)
{
	//
	// Declare tracking variables of list position and temporary nodes
	//
	int position = 0;
	int lstCounter = 0;
	Node *tmp;
	Node *tmp2;

	//
	// if myList or given is NULL/UNDEFINED, set position to -1
	//
	if (myList == NULL || given == NULL)
	{
		position = -1;
	}
	if (myList == UNDEFINED || given == UNDEFINED)
	{
		position = -1;
	}

	if (myList != NULL && myList != UNDEFINED && given != NULL
	    && given != UNDEFINED)
	{
		//
		// While loop/tmp2 used to count size of list
		//
		tmp2 = myList->engine;
		while (tmp2 != NULL)
		{
			lstCounter++;
			tmp2 = tmp2->to;
		}

		//
		// Loop to check position of given in list
		//
		tmp = myList->engine;
		while (tmp != NULL)
		{
			if (tmp == given)
			{
				break;
			}
			position++;
			tmp = tmp->to;
		}
	}

	//
	// if position counter is the size of the list, node item is not in list.
	//
	if (position == lstCounter)
	{
		position = -2;
	}			// if position reaches last position, node not in list, returns position -2.
	return (position);
}

//////////////////////////////////////////////////////////////////////
//
// setpos() - a list library utility function to set a node pointer
//                      to the node at the indicated position of a list.
//
//        note: Indexing of the list starts from 0
//
//  behavior: on error (NULL/UNDEFINED list or negative/out-of-bounds
//                      pos), return NULL.
//
//                      you are to have only ONE return statement for this
//                      entire function. Change the existing one as needed.
//
Node *setpos(List * myList, int pos)
{
	//
	// Declare counter variable and temporary node for traversing list.
	//
	Node *tmp;
	int lstCounter = 0;

	//
	// if List is NULL or UNDEFINED return NULL/UNDEFINED Node
	//
	if (myList == NULL)
	{
		tmp = NULL;
	}
	else if (myList == UNDEFINED)
	{
		tmp = UNDEFINED;
	}

	//
	// Else, traverse the list and set the position 
	//
	else if (myList != UNDEFINED && myList != NULL)
	{
		tmp = myList->engine;
		while (tmp != NULL)
		{
			if (lstCounter == pos)
			{
				break;
			}
			tmp = tmp->to;
			lstCounter++;
		}
	}

	//
	// return node at set position
	//
	return (tmp);
}
