
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//                        at the indicated place. insert() needs to manage
//                        the necessary connections pointers) to maintain list
//                        integrity, along with ensuring the start and end
//                        indicators of the list remain relevant and up-to-date.
//
//      behavior: on an UNDEFINED list- do nothing; return list as is
//                        on a NULL list- allocate a list and proceed
//                        on a NULL or UNDEFINED newNode- return list as is
//
//              note: you are expected to make use of the getpos() and
//                        setpos() functions to aid you in accomplishing this
//                        task. Don't needlessly reinvent the wheel.
//
//                        as with the other functions, you may use no more
//                        than one return() statement per function.
//
List *insert(List * myList, Node * place, Node * newNode)
{
	//
	// Initialize position in list variable and tmp node variable
	//
	int position;
	Node *tmp;

	//
	// Check if list is empty or NULL, create new list if NULL list.
	//
	if (myList == NULL)
	{
		myList = mklist();
	}

	if (place != NULL || newNode != NULL)
	{
		tmp = myList->engine;

		if (place == myList->engine )
			//
			// inserting node at the front of the list
			//
		{
			newNode->to = myList->engine;
			myList->engine = newNode;
		}

		//
		// Insert a node before the end of a list
		//
		else if (place == myList->caboose && tmp != NULL)
		{
			// andrei check tmp->to->to	
			while (tmp->to->to != NULL)
			{
				tmp = tmp->to;
			}
			

			//
			// Set position of tmp node two index  places before caboose
			// insert new node
			//
			position = getpos(myList, tmp);
			tmp = setpos(myList, position);
			myList->caboose = tmp->to;
			tmp->to = newNode;
			tmp->to->to = myList->caboose;
		}
		//
		// Insert a node anywhere else in the list
		//
		else
		{
			//
			// set tmp node 1 index before given place
			// insert new node
			//
			position = getpos(myList, place);
			tmp = setpos(myList, position - 1);
			newNode->to = tmp->to;
			tmp->to = newNode;
		}
	}
	//
	// return new list with inserted node
	//
	return (myList);
}
