#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//    behavior: on a NULL list- do nothing; return NULL.
//              on an UNDEFINED list- do nothing, return list as is
//              on a NULL thatNode- do nothing; return list as is
//              on UNDEFINED thatNode- do nothing; return list as is
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatNode, the one
//              being isolated from the list, is being passed in as a
//              double pointer (we're passing the Node pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *obtain(List * myList, Node ** thatNode)
{
	//
	// Declare variables for two tmp nodes to traverse list, and position for
	// position of thatNode
	//
	int position;
	Node *tmp;

	//
	// Check if myList is UNDEFINED, NULL, OR EMPTY,  if so, do nothing, else
	// go to following if statements to disconnect/obtain nodes
	//
	if (myList != NULL && myList != UNDEFINED && *thatNode != NULL
	    && *thatNode != UNDEFINED)
	{
		//
		// Check that the list isn't empty before going through program
		//
		if (myList->engine != NULL && myList->caboose != NULL)
		{
			//
			// Obtain from one node list. disconnect thatnode and set all
			// list pointers to NULL (empty).  
			//
			if (myList->engine == myList->caboose)
			{
				myList->engine = NULL;
				myList->caboose = NULL;

				(*thatNode)->to = NULL;
				myList->qty -= 1;
			}

			//
			// Obtaining from two node list
			//
			else if (myList->engine->to == myList->caboose)
			{
				//
				// Check if obtaining from first or 2nd node, then
				// rearrange node pointers correctly. 
				//
				if ((*thatNode) == myList->engine)
				{
					myList->engine = myList->caboose;
					(*thatNode)->to = NULL;
				}
				else if ((*thatNode) == myList->caboose)
				{
					myList->caboose = myList->engine;
					myList->caboose->to = NULL;
					(*thatNode)->to = NULL;
				}
				myList->qty -= 1;
			}
			//
			//  Obtaining from the beginning of the list
			//      If obtaining from the beginning of the list, point
			//  myList engine to tmp->to, which is positioned at the node directly
			//  after the beginning, disconnecting original engine
			//
			else if ((*thatNode) == myList->engine)
			{

				myList->engine = (*thatNode)->to;	// was tmp->to
				(*thatNode)->to = NULL;
				myList->qty -= 1;
			}

			//
			// Obtaining from the end of a list
			// tmp is set to the second to last node in the list,
			// then we point the end of the list to tmp, pointing tmp->to
			// to NULL now that it is at the end, thus disconnecting
			// original caboose
			//
			else if ((*thatNode) == myList->caboose)
			{
				position = getpos(myList, *thatNode);
				tmp = setpos(myList, position - 1);
				myList->caboose = tmp;
				tmp->to = NULL;

				(*thatNode)->to = NULL;

				myList->qty -= 1;
			}

			//
			// Obtaining from the middle of the list
			// In most scenarios we obtain from the middle of the list.
			// In this case, we set tmp2 before the position of thatNode,
			// and tmp to the position of thatNode.  Then, tmp2 points to tmp->to,
			// thus disconnecting tmp (position of thatNode) from the list
			//
			else
			{
				position = getpos(myList, *thatNode);
				tmp = setpos(myList, position - 1);
				tmp->to = (*thatNode)->to;
				(*thatNode)->to = NULL;
				myList->qty -= 1;

			}
		}

	}
	//
	// return new list after obtaining
	//
	return (myList);

}
