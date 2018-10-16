#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// cpnode() - a node library function to duplicate a node and its 
//                      contents -- it must call other functions as needed, and
//                      take care to ensure all aspects of the source node have
//                      been successfully replicated in the copied node.
//
//  behavior: on error or NULL source node, return NULL.
//
//        NOTE: you are to have only ONE return statement for this
//                      entire function. Change the existing one as needed.
//
//                      the contents of the "to" pointer, if non-NULL,
//                      should be pointing to any next node (even though we
//                      are not copying it here).
//
Node *cpnode(Node * curNode)
{
	//
	// Declare value and make new node if curNode isn't NULL
	//

	char value;
	Node *newNode;

	if (curNode != NULL)
	{
		value = curNode->contents;
		newNode = mknode(value);
	}

	//
	// if curNode pointer is not pointing to NULL and curNode is not NULL, copy the behavior
	// for newNode. If curNode->to is not NULL, allocate memory/contents of curNode-> to and
	// copy the value as well.
	//

	if (curNode != NULL)
	{

		if (curNode->to != NULL)
		{
			newNode->to = (Node *) malloc(sizeof(Node));
			newNode->to = curNode->to;
			newNode->to->to = NULL;
		}
	}

	//
	// return either Null or copied node
	//

	return (newNode);
}
