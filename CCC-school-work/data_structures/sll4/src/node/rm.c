#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// rmnode() - a node library function to clear and deallocate an 
//			existing node
//
//	  NOTE: you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
Node *rmnode(Node *oldNode)
{	
	//
	// deallocate the memory of oldNode
	//
	free(oldNode);
	return(0);
}
