#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// cplist() - a list library function to duplicate or copy an existing
//            list and all its component nodes.
//
//            the operative idea here is "separate copies"; you may
//            want to make use of cpnode() to assist.
//
//  behavior: on error, return NULL.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *cplist(List * oldList)
{
	//
	// Declare new list and tmp variables for traversing both old and new list
	//
	List *newList;
	Node *tmp;
	Node *tmp2;

	//
	// Check that old List is not NULL. If it is, the newList should be NULL
	//
	if (oldList == NULL)
	{
		newList = NULL;
	}

	//
	// If old List is not NULL and oldList does not have a NULL engine,
	// use tmp and tmp2 to traverse both old/new list, then copy oldList Nodes
	// into newList
	//
	else
	{
		//
		// Make new list to be copied over to from oldList one at a time
		//
		newList = mklist();
		if (oldList->engine != NULL)
		{
			tmp = oldList->engine;
			tmp2 = mknode(tmp->contents);
			newList->engine = tmp2;
			newList->caboose = tmp2;

			while (tmp->to != NULL)
			{
				tmp = tmp->to;
				tmp2->to = mknode(tmp->contents);
				tmp2 = tmp2->to;
				newList->caboose = tmp2;
			}
			//
			// Set newLists next list/qty to the same as old List
			//
		}
		newList->next = oldList->next;
		newList->qty = oldList->qty;
	}
	//
	// You now have a copied list. New List is returned.
	//
	return (newList);
}
