
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

	if (myList != UNDEFINED && myList != NULL && newNode != NULL)
	{
		//
		// insert in empty List. If List is empty, make newNode the 
		// engine and caboose.
		//
		if (myList->engine == NULL && myList->caboose == NULL)
		{
			myList->engine = newNode;
			myList->caboose = newNode;
			newNode->to = NULL;
		}
		//
		// insert in one node list. If one node list, 
		// newNode becomes the engine, and it points to the
		// caboose
		//
		else if (myList->engine == myList->caboose)
		{
			newNode->to = myList->caboose;
			myList->engine = newNode;
		}

		//
		// Insert at beginning ( greater than one node list)
		// newNode becomes the new engine, and points to the old engine
		//
		else if (place == myList->engine )
		{

			newNode->to = myList->engine;
			myList->engine = newNode;

		}

		//
		// Insert at end. ( greater than one node list)
		// newNode points to the caboose, as it is inserted
		// before the caboose
		//
		else if (place == myList->caboose )
		{
			position = getpos(myList, place);
			tmp = setpos(myList, (position - 1));
			newNode->to = myList->caboose;
			tmp->to = newNode;

		}
		//
		// Insert in middle. Place the new node in the middle of the list,
		// setting tmp before the place of insert, and pointing it to the new
		// node.
		//
		else if (place != NULL)
		{
			position = getpos(myList, place);

			tmp = setpos(myList, (position - 1));
			newNode->to = tmp->to;
			tmp->to = newNode;
		}

		//
		// With both insert and append, list quantity grows
		//
		myList->qty += 1;
	}

	//
	// Make new list if NULL list
	//
	else if (myList == NULL)
	{
		myList = mklist();
	}

	//
	// return new list with inserted node
	//
	return (myList);
}
