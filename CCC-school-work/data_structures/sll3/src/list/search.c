#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// searchlist() - a list library utility function to locate a node in
//                an existing list by value it contains.
//
//      note: unlike getpos()/setpos(), which worked in units of list
//            positional offsets, searchlist() focuses on the actual
//            content of what is in the nodes, returning a pointer to
//            the initial node that contains the matching value (from 
//            the start of the list).
//
//  behavior: on error (NULL/UNDEFINED list, NULL node, no match),
//            return NULL
//
//            you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *searchlist(List * myList, char value)
{
	//
	// Declare tmp node to traverse list and seek value
	// Declare trigger to go off when node is located
	//
	Node *tmp;
	int trigger = 0;

	//
	// Before executing traersal, make sure list it not NULL, empty, or UNDEFINED
	//
	if (myList != UNDEFINED && myList != NULL)
	{
		if (myList->engine != NULL)
		{
			//
			// Set tmp equal to first list element and begin seeking for value node
			// if value found, set off trigger, and return tmp node
			//
			tmp = myList->engine;
			while (tmp != NULL)
			{
				if (tmp->contents == value)
				{
					trigger = 1;
					break;
				}
				tmp = tmp->to;
			}
		}

////////////////////////////////////////////////////////////
//
// set tmp to NULL if trigger isn't hit (node value not found)
// or if NULL/UNDEFINED/EMPTY list
//
		else
		{
			tmp = NULL;
		}
	}
	else
	{
		tmp = NULL;
	}

	if (trigger == 0)
	{
		tmp = NULL;
	}

	return (tmp);
}
