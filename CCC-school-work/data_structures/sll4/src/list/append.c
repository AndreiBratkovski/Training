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
		// Append on empty list. Make newNode both engine and caboose, since it
		// is not the only node in the list
		//
		if (myList->engine == NULL && myList->caboose == NULL)
		{
			myList->engine = newNode;
			myList->caboose = newNode;
			newNode->to = NULL;
		}

		//
		// Append on one node list. newNode is now the caboose, as it is being
		// added to a one node list
		//
		else if (myList->engine == myList->caboose)
		{
			myList->engine->to = newNode;
			myList->caboose = newNode;
		}
		//
		// If above is not executed, check if appending to the beginning
		// Since the list is greater than one node, the Node is dropped in the list,
		// leavning engine/caboose intact
		//
		else if (place == myList->engine )
		{

			newNode->to = myList->engine->to;
			myList->engine->to = newNode;
		}
		//
		// if asked to append to the end of the list, 
		// newNode is tacked on the end, and becomes the new
		// caboose
		//
		else if (place == myList->caboose )
		{
			position = getpos(myList, place);
			tmp = setpos(myList, position);
			tmp->to = newNode;
			myList->caboose = newNode;
		}
		//
		// If somewhere in the middle of the list, set tmp at position, and
		// append/link new node into place after tmp 
		//
		else if (place != NULL )
		{
			position = getpos(myList, place);
			tmp = setpos(myList, position);
			newNode->to = tmp->to;
			tmp->to = newNode;
		}

		//
		// add to list qty since it is growing
		//
		myList->qty += 1;
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
