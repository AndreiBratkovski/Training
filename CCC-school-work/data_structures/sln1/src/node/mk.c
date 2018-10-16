#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// mknode() - a node library function to allocate and initialize a 
//                      new node.
//
//  behavior: on error, return NULL.
//
//        NOTE: you are to have only ONE return statement for this
//                      entire function. Change the existing one as needed.
//
Node *mknode(char value)
{
	//
	// Allocate memory for newNode and declare Node type newNode
	//
	Node *newNode;

	newNode = (Node *) malloc(sizeof(Node));

	//
	// Check if newNode is NULL. if not NULL, assign contents and struct pointer
	//
	if (newNode != NULL)
	{
		newNode->contents = value;
		newNode->to = NULL;
	}

	return (newNode);
}
