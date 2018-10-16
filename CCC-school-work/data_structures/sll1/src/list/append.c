#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the initial and closing
//              pointers of the list remain relevant and up-to-date.
//
//    behavior: on an UNDEFINED list- do nothing; return list as is
//              on a NULL list- allocate a list and proceed
//              on a NULL or UNDEFINED newNode- return list as is
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *append(List * myList, Node * place, Node * newNode)
{
	//
	// Declare tmp variable and position variable for traversing the list
	//
	Node *tmp;
	int position;

	//
	// Before execcting any of the below commands, make sure that the List
	// is not UNDEFINED or EMPTY
	//
	if (myList != UNDEFINED && myList != NULL && newNode != NULL)
	{

		//
		// If somewhere in the middle of the list, use tmp to traverse and
		// append/link new node into place
		//
		if (place != myList->engine && place != myList->caboose)
		{
			position = getpos(myList, place);

			tmp = myList->engine;
			tmp = setpos(myList, position);
			newNode->to = tmp->to;
			tmp->to = newNode;
		}
		//
		// If above is not executed, check first if appending to the beginning
		// of the list
		//
		else if (place == myList->engine && newNode != NULL)
		{
			//
			// if the list is empty, the engine becomes the new node
			//
			if (myList->engine == NULL)
			{
				myList->engine = newNode;
			}
			//
			// else, plae new node after engine 
			//
			else
			{
				newNode->to = myList->engine->to;
				myList->engine->to = newNode;
			}
		}
		//
		// if asked to append to the end of the list, 
		// use tmp to traverse to the end and append new node
		//
		else if (place == myList->caboose)
		{
			tmp = myList->engine;
			while (tmp->to != NULL)
			{
				tmp = tmp->to;
			}
			tmp->to = newNode;
			myList->caboose = newNode;
		}
	}

	//
	// if list is empty, return allocated new list
	//
	else if (myList == NULL)
	{
		myList = mklist();
	}

	return (myList);
}
